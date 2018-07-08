/*
	draft2mg v0.1 by 4wekromi (march 2017)
	-Convert keys to standard frequencies
	-Convert draft.txt to music.mg
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float keyFreq[]={32.70,34.64,36.70,38.89,41.20,43.65,46.24,48.99,51.91,
	55,58.27,61.73,65.40,69.29,73.41,77.78,82.40,87.30,92.49,97.99,103.82,
	110,116.54,123.47,130.81,138.59,146.83,155.56,164.81,174.61,184.99,195.99,207.65,
	220,233.08,246.94,261.62,277.18,293.66,311.12,329.62,349.22,369.99,391.99,415.30,
	440,466.16,493.83,523.25,554.36,587.32,622.25,659.25,698.45,739.98,783.99,830.60,
	880,932.32,987.76,1046.50,1108.73,1174.65,1244.50,1318.51,1396.91,1479.97,1567.98,1661.21,
	1760,1864.65,1975.53,2093,0.0};

/*Available keys*/
char keyN[][3]={"c1","c1#","d1","d1#","e1","f1","f1#","g1","g1#","a1","a1#","b1",
		"c2","c2#","d2","d2#","e2","f2","f2#","g2","g2#","a2","a2#","b2",
		"c3","c3#","d3","d3#","e3","f3","f3#","g3","g3#","a3","a3#","b3",
		"c4","c4#","d4","d4#","e4","f4","f4#","g4","g4#","a4","a4#","b4",
		"c5","c5#","d5","d5#","e5","f5","f5#","g5","g5#","a5","a5#","b5",
		"c6","c6#","d6","d6#","e6","f6","f6#","g6","g6#","a6","a6#","b6",
		"c7"};

char outFile[32];
char inFile[32];
char keyCh[3];
char keyDe[4];

struct mdata
{
	float keyF;
	float keyD;
} mk;

int getFq(){
	int inKey=0;
	int j=0;
	while(j!=73){
		if(keyCh[0]==keyN[j][0]){
			if(keyCh[1]==keyN[j][1]){
				if(keyCh[2]==keyN[j][2]){
					inKey=j;
					break;
				}
				else{
					inKey=j;
					j++;
					}
				}
				else
				   j++;
				}
			else{
				j++;
				inKey=73;
			}
		}
	mk.keyF=keyFreq[inKey];
	return 0;
}

int buffer(int flag, char in){
	static int i;
	int x;
	FILE *ptr=fopen(outFile,"ab");
	if (in == '*')
		i = 0;
	else if (in == '@')
		i = 0;
	if (flag == 1 && in != '*'){
		keyCh[i] = in;
		i++;
	}
	else if (flag == 2 && in != '@'){
		keyDe[i] = in;
		i++;
	}
	else if (flag == 3&&in=='&')
	{
		mk.keyD=atoi(keyDe);
		getFq();
		fwrite(&mk,sizeof(mk),1,ptr);
		for(x=0;x<5;x++){
			keyCh[x]='\0';
			keyDe[x]='\0';
		}
	}
	fclose(ptr);
	return 0;
}

int main(){
	char ch;
	char temp[32];
	int flag;
	FILE *fp;
	FILE *ptr2;
	clrscr();
	fflush(stdin);
	printf("Enter draft file name (eg draft) : ");
	gets(temp);
	sprintf(inFile,"%s.txt",temp);
	printf("Enter output file name (eg canon) : ");
	gets(temp);
	sprintf(outFile,"%s.mg",temp);
	fp=fopen(outFile,"r");
	if(fp!=NULL){
		remove(outFile);
		printf(" removed existing file %s",outFile);
	}
	ptr2=fopen(inFile,"r");
	if(ptr2==NULL){
		printf("\n Error : %s not found ",inFile);
		getch();
		exit(1);
	}
	while (!feof(ptr2)){
			ch = getc(ptr2);
			if (ch == '*')
				flag = 1;
			else if (ch == '@')
				flag = 2;
			else if (ch == '&')
				flag = 3;
			buffer(flag, ch);
	}
	printf("\n..Done");
	getch();
	fclose(ptr2);
	return 0;
}
