#include <vector>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "structs.h"

int nameArrayLen = 217;
wchar_t *nameArray[] = {
	L"�H�H�H",  	L"???", 
	L"�H�H",  	L"??", 
	L"�H",  	L"?", 
	L"��������",  	L"Old Man", 
	L"���΂������",  	L"Old Lady", 
	L"����",  	L"Gil", 
	L"���܂�",  	L"Shimako", 
	L"���͂�",  	L"Chihaya", 
	L"�Ƃ���",  	L"Tomoko", 
	L"�˂�",  	L"Neko", 
	L"�ς�",  	L"Pani", 
	L"��ڂ�",  	L"Ribbon", 
	L"�C�^�`",  	L"Itachi", 
	L"�I�o�`����",  	L"Old Lady", 
	L"�N���X���C�g",  	L"Classmate", 
	L"�P���[",  	L"Kelly", 
	L"�c�`�m�R��",  	L"Clumsy Woman", 
	L"�e���r",  	L"TV", 
	L"�n���J",  	L"Haruka", 
	L"�~�h�E",  	L"Midou", 
	L"���`�A",  	L"Lucia", 
	L"���[�u�̒j",  	L"Robed Man", 
	L"����",  	L"Ansai", 
	L"���",  	L"Inoue", 
	L"�ꓯ",  	L"Everyone", 
	L"��N���q",  	L"First-Year Girl", 
	L"��N��",  	L"First-Year", 
	L"��N���j�q",  	L"First-Year Boy", 
	L"��N�j�q",  	L"First-Year Boy", 
	L"��N�j�q�i�h��j",  	L"First-Year Boy (flashy)", 
	L"��N��؂`",  	L"First-Year Suzuki A", 
	L"��N��؂a",  	L"First-Year Suzuki B", 
	L"�p�ꕶ",  	L"English Text", 
	L"�Ԏq�H",  	L"Hanako?", 
	L"�g��",  	L"Yoshino", 
	L"�~�}����",  	L"�~�}����", 
	L"���t",  	L"Teacher", 
	L"�x�����`",  	L"Guard A", 
	L"�x�����a",  	L"Guard B", 
	L"��",  	L"Dog", 
	L"������",  	L"Researcher", 
	L"��",  	L"Key", 
	L"���̏���",  	L"Key", 
	L"���",  	L"Ex-president", 
	L"�葾�N�E����",  	L"Kotarou & Kotori", 
	L"�葾�N�E�P",  	L"Kotarou & Ootori", 
	L"�葾�N",  	L"Kotarou", 
	L"�]��",  	L"Esaka", 
	L"�]��",  	L"Egashira", 
	L"�����̒j",  	L"Contemporary Man", 
	L"�����̒j",  	L"Contemporary Man", 
	L"���",  	L"Sakuya", 
	L"�O�N���q",  	L"Third-Year Girl", 
	L"�O�N�����q",  	L"Third-Year Girl", 
	L"�O�N���j�q",  	L"Third-Year Boy", 
	L"�O�N�j�q",  	L"Third-Year Boy", 
	L"�q��",  	L"Child", 
	L"���]�ԉ�",  	L"Bicycle Shop", 
	L"�鉹",  	L"Akane", 
	L"��",  	L"Woman", 
	L"���̎q",  	L"Girl", 
	L"���̐�",  	L"Female Voice", 
	L"���q���k",  	L"Schoolgirl", 
	L"���q���k�`",  	L"Schoolgirl A", 
	L"���q���k�a",  	L"Schoolgirl B", 
	L"���q���k�b",  	L"Schoolgirl C", 
	L"����",  	L"Woman", 
	L"�����̐�",  	L"Woman's Voice", 
	L"�����k",  	L"Schoolgirl", 
	L"���w��",  	L"Elementary Schoolkid", 
	L"����",  	L"Kotori", 
	L"����",  	L"Girl", 
	L"���N",  	L"Boy", 
	L"�E��",  	L"Staff", 
	L"�a�m",  	L"Gentleman", 
	L"�{�X��",  	L"Suzuki", 
	L"���k",  	L"Student", 
	L"���k����",  	L"Students", 
	L"��",  	L"Voice", 
	L"�×�",  	L"Shizuru", 
	L"��y���q",  	L"Girl", 
	L"��j",  	L"Man", 
	L"�S�C",  	L"Teacher", 
	L"�j",  	L"Man", 
	L"�j�q",  	L"Boy", 
	L"�j�q���k",  	L"Schoolboy", 
	L"�j�q���k�`",  	L"Schoolboy A", 
	L"�j�q���k�a",  	L"Schoolboy B", 
	L"�j�q���k�b",  	L"Schoolboy C", 
	L"��",  	L"Boar", 
	L"�Ëv��",  	L"Tsukuno", 
	L"�d�b",  	L"Phone", 
	L"�d�b�̑���",  	L"Man on Phone", 
	L"��l",  	L"��l", 
	L"��N���q",  	L"Second-Year Girl", 
	L"��N�j�q",  	L"Second-Year Boy", 
	L"���{�ꕶ",  	L"Japanese Text", 
	L"����n�������j",  	L"Tattoed Man", 
	L"�L",  	L"Cat", 
	L"�s�R�l��",  	L"Suspicious Person", 
	L"����̒j",  	L"Happy-Looking Man", 
	L"�ҏW",  	L"Editor", 
	L"�ҏW��",  	L"Editor", 
	L"�P",  	L"Ootori", 
	L"����",  	L"Witch", 
	L"�����q",  	L"Rikako", 
	L"���",  	L"Suzuki", 
	L"�V�k",  	L"Old Woman", 
	L"�F��",  	L"Suzaki"
};

typedef struct _NewlineAssociation
{
	int line;
	int offset;
	int type;
} NewlineAssociation;

vector<NewlineAssociation*> newlines;

int main(int argc, char **argv)
{
	FILE *infile = NULL, *outfile = NULL;
	Entry *strings = NULL;
	unsigned char *bytecode = NULL;
	int i = 0;
	
	if(argc!=3)
	{
		printf("usage: %s inscript outtext\n",argv[0]);
		return 0;
	}
	
	infile = fopen(argv[1],"rb");
	if(!infile)
	{
		printf("Could not open %s\n",argv[1]);
		return -1;
	}
	
	outfile = fopen(argv[2],"wb");
	fwrite("\xff\xfe",1,2,outfile);
	
	setlocale(LC_ALL, "Japanese");
	
	fread(&scrhead,sizeof(scrhead),1,infile);
	
	bytecode = (unsigned char*)calloc(scrhead.bytecode.size,sizeof(unsigned char));
	fseek(infile,scrhead.bytecode.offset,SEEK_SET);
	fread(bytecode,1,scrhead.bytecode.size,infile);
	
	fwprintf(outfile,L"// Newline command format: {0000} (newline type)\r\n// 0d = append\r\n// 0e = new page\r\n// anything else is unknown\r\n\r\n");
	
	for(i = 0; i < scrhead.bytecode.size; i++)
	{
		static unsigned char pushString[] = { 0x02, 0x14, 0x00, 0x00, 0x00 };
		static unsigned char pushNewline[] = { 0x02, 0x0a, 0x00, 0x00, 0x00 };
		static unsigned char pushNewline2[] = { 0x30, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 00, 03, 00, 00, 00, 00 };
		int x = 0;
		
		if(memcmp(bytecode+i, pushString, 5) == 0)
		{
			unsigned int stringNum = *(unsigned int*)(bytecode+i+5);
			unsigned int pushType = 0;
			int foundPush = 0;
				
			for(x = i + 5; x < scrhead.bytecode.size - 5; x++)
			{
				if(x - i > 0x100)
					break;
					
				if(memcmp(bytecode+x, pushString, 5) == 0)
					break;
					
				if(memcmp(bytecode+x, pushNewline, 5) == 0 && memcmp(bytecode+x+9, pushNewline2, 0x16) == 0)
				{
					foundPush = 1;
					pushType = *(unsigned int*)(bytecode+x+5);
					break;
				}
			}	
				
			if(foundPush && pushType != 0x0e)
			{
				//printf("Found match at %08x (#%d) (%02x) // line %d\n",scrhead.bytecode.offset+i,stringNum, pushType, stringNum);
				//fwprintf(outfile,L"{%04x} %02x // line <%04d>\r\n", x+5, pushType, stringNum);
				
				NewlineAssociation *newline = (NewlineAssociation*)calloc(1, sizeof(NewlineAssociation));
				newline->line = stringNum;
				newline->offset = x+5;
				newline->type = pushType;
				newlines.push_back(newline);
			}
			else
			{
				//printf("Could not find push\n");
			}
			//exit(1);
		}	
	}
	
	strings = (Entry*)calloc(scrhead.strindex.size,sizeof(Entry));
	fseek(infile,scrhead.strindex.offset,SEEK_SET);
	fread(strings,sizeof(Entry),scrhead.strindex.size,infile);
	
	for(i=0; i<scrhead.strindex.size; i++)
	{
		wchar_t *line = (wchar_t*)calloc(strings[i].size+1,sizeof(wchar_t));
		wchar_t *lineparsed = (wchar_t*)calloc(strings[i].size*2,sizeof(wchar_t));
		int x = 0, j = 0, l = 0;
		int key = 0;
		
		fseek(infile,scrhead.strtable.offset+strings[i].offset*sizeof(wchar_t),SEEK_SET);
		fread(line,sizeof(wchar_t),strings[i].size,infile);
		
		// for v2.00 of rewrite trial (and probably newer siglusengine stuff)
		key = i * 0x7087;
		for(l=0; l<strings[i].size; l++)
		{
			line[l] ^= key; 
		}
		
		fwprintf(outfile,L"//");
		for(l=0; l<2; l++)
		{
			fwprintf(outfile,L"<%04d> ",i);
			
			if(l > 0)
			{
				int nameFound = 0;
				
				for(x = 0; x < nameArrayLen; x+=2)
				{
					if(wcscmp(line,nameArray[x])==0)
					{
						fwprintf(outfile,L"%s",nameArray[x+1]);
						nameFound = 1;
						break;
					}
				}
				
				if(nameFound)
				{
					fwprintf(outfile,L"\r\n");
					break;
				}
			}
			
			for(x=0,j=0; x<strings[i].size; j++, x++)
			{
				if(line[x]=='\n')
					fwprintf(outfile,L"\\n");
				else
					fwprintf(outfile,L"%c",line[x]);
			}
		
			fwprintf(outfile,L"\r\n");
		}
		
		for(x = 0; x < newlines.size(); x++)
		{
			if(newlines[x]->line == i)
			{
				//printf("Found match: {%04x} %02x // line <%04d>\n", newlines[x]->offset, newlines[x]->type, newlines[x]->line);
				fwprintf(outfile,L"{%04x} %02x // %04d\r\n", newlines[x]->offset, newlines[x]->type, newlines[x]->line);
				break;
			}
		}
		fwprintf(outfile,L"\r\n");
		
		free(line);
	}
	
	return 0;
}
