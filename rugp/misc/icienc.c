#include <stdio.h>
#include <stdlib.h>

unsigned int size1=0,size2=0;

int GetRemainder(int num1, int num2)
{
	int retVal = 0;

	__asm
	{
		pushad
		mov eax, num2
		imul num1
		mov retVal, edx	
		popad
	}

	return retVal;
}

void DecryptICI2(int size, unsigned char *buffer, unsigned char *buffer2)
{	
	int splitSize = GetRemainder(size,0x2aaaaaab);
	int i=0,x=0,j=0;
	unsigned char temp = 0;

	splitSize += splitSize>>0x1f;

	for(x=0,i=0,j=splitSize; j>0; j--)
	{
		buffer2[x] = buffer[i];
		buffer2[x+1] = buffer[i+splitSize];
		buffer2[x+2] = buffer[i+splitSize*2];
		x += 6;

		buffer2[x-3] = buffer[i+splitSize*3];
		i++;
		
		buffer2[x-2] = buffer[i+splitSize*4-1];
		buffer2[x-1] = buffer[i+splitSize*5-1];
	}

	for(; x<size; x++)
		buffer[x] = buffer2[x];

	for(i=0; i<size; i++)
	{
		buffer2[i] = buffer2[i]-temp;
		temp = buffer2[i]+temp;
		buffer2[i] ^= 0xa5;
	}

	splitSize = GetRemainder(size,0x66666667)>>1;
	splitSize += splitSize>>0x1f;

	for(x=0,i=0,j=splitSize; j>0; j--)
	{
		buffer[x] = buffer2[i];
		buffer[x+1] = buffer2[i+splitSize];
		buffer[x+2] = buffer2[i+splitSize*2];
		x += 5;

		buffer[x-2] = buffer2[i+splitSize*3];
		i++;
		
		buffer[x-1] = buffer2[i+splitSize*4-1];
	}

	for(; x<size; x++)
		buffer[x] = buffer2[x];

	for(temp=0,x=size-1; x>=0; x--)
	{
		buffer[x] = buffer[x]-temp;
		temp = buffer[x]+temp;
	}	

	splitSize = GetRemainder(size,0x55555556);
	splitSize += splitSize>>0x1f;

	for(x=0,i=0,j=splitSize; j>0; j--)
	{
		x+=3;
		
		buffer2[x-3] = buffer[i]^0x18;
		buffer2[x-2] = buffer[i+splitSize]^0x3f;
		buffer2[x-1] = buffer[i+splitSize*2]^0xe2;	
		i++;
	}

	for(; x<size; x++)
		buffer2[x] = buffer[x];
}

void DecryptICI(FILE *infile, FILE *outfile)
{	
	unsigned char *buffer = NULL;
	unsigned char *buffer2 = NULL;
	unsigned int tempKey=0, key=0xB29D5A0C;
	int decAmt=0x20, i=0, x=0, size1t=0,size2t=0,outsize=0;

	fseek(infile,0,SEEK_END);
	size1 = size2 = outsize = ftell(infile);
	rewind(infile);

	buffer = (unsigned char*)calloc(size1*4,sizeof(unsigned char));

	size1t = ~size1^0xC92E568B;
	size2t = (size2<<3)^0xC92E568F;
	
	fwrite(&size1t,1,4,outfile);
	fwrite(&size2t,1,4,outfile);
	
	buffer2 = (unsigned char*)calloc(size1*4,sizeof(unsigned char));
	fread(buffer2,1,size1,infile);
	DecryptICI2(size1,buffer2,buffer);
	fwrite(buffer2,1,size1,outfile);
	fclose(outfile);
	//printf("%02x%02x%02x%02x%02x%02x%02x%02x\n",buffer2[0],buffer2[1],buffer2[2],buffer2[3],buffer2[4],buffer2[5],buffer2[6],buffer2[7]);
	exit(1);

	for(i=size1; i>0;)
	{
		decAmt = i%0x20;

		if(decAmt==0)
			decAmt = 0x20;

		i-=decAmt;

		fread(buffer+x,1,decAmt,infile);

		for(; decAmt>0; decAmt--,x++)
		{
			buffer[x] ^= (key&0x000000ff);
			tempKey = (key>>0x0f)&1;
			key = ~(key*2+tempKey+0xA3B376C9);
		}

		//fread(&size2,1,2,infile);
		buffer[x++] = '\0';
		buffer[x++] = '\0';
		outsize += 2;
	}

	fwrite(buffer,1,outsize,outfile);
}

int main(int argc, char **argv)
{
	FILE *infile = fopen(argv[1],"rb");
	FILE *outfile = fopen(argv[2],"wb");

	DecryptICI(infile,outfile);

	fclose(infile);
	fclose(outfile);
}
