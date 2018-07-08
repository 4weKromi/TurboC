/*
	File Operations modules
*/

#include "GLOBAL.H"

extern char fnameA[];
extern char fnameB[];
extern char fnameC[];
extern char fnameD[];
extern char fnameE[];
extern char tmpList[];
extern char mgArr[3][32];
extern char mgBuff[];
extern char mgList[];
extern char buff[];

/* MG data structure */
struct keyData{
	float keyF;
	float keyD;
}mk;

/* setting files to open */
int setFiles(){
	int x;
	int flag,i,j=0;
	char ch;
	FILE *ptr = fopen(mgList, "r");
	if (ptr == NULL)
		ptr=fopen(mgList,"w");
	for(i=0;i<32;i++){
		buff[i]='\0';
		fnameC[i]='\0';
		fnameD[i]='\0';
		fnameE[i]='\0';
		mgArr[0][i]='\0';
		mgArr[1][i]='\0';
		mgArr[2][i]='\0';
	}
	i=0;
	while (!feof(ptr)){
		ch = getc(ptr);
		if (ch == '>')
			flag = 1;
		else if (ch == ';'){
			flag = 0;
			i=0;
			j++;
		}
		if (flag == 1 && ch != '>'){
			mgArr[j][i] = ch;
			i++;
		}
	}
	setcolor(BLUE);
	outtextxy(40,162,fnameA);
	outtextxy(40,212,fnameB);
	for(x=0;buff[x]!='\0';x++)
		buff[x]='\0';
	for(x=0;mgArr[0][x]!='\0';x++)
		buff[x]=mgArr[0][x];
	sprintf(fnameC,"%s",buff);
	outtextxy(40,262,fnameC);
	for(x=0;buff[x]!='\0';x++)
		buff[x]='\0';
	for(x=0;mgArr[1][x]!='\0';x++)
		buff[x]=mgArr[1][x];
	sprintf(fnameD,"%s",buff);
	outtextxy(40,312,fnameD);
	for(x=0;buff[x]!='\0';x++)
		buff[x]='\0';
	for(x=0;mgArr[2][x]!='\0';x++)
		buff[x]=mgArr[2][x];
	sprintf(fnameE,"%s",buff);
	outtextxy(40,362,fnameE);
	fclose(ptr);
	return 0;
}

/* loading .mg file to memory */

struct node{
	struct keyData sf;
    	struct node *next;
	struct node *prev;
}*top;

int pushToMem(float k,float d){
	struct node *tmpNode;
	tmpNode=(struct node*)malloc(sizeof(struct node));
	tmpNode->sf.keyF=k;
	tmpNode->sf.keyD=d;
	tmpNode->prev=NULL;
	if(top==NULL)
		tmpNode->next=NULL;
	else{
		tmpNode->next=top;
		top->prev=tmpNode;
	}
	top=tmpNode;
	return 0;
}

int loadFile(char filename[]){
	int index=0;
	FILE *ptr=fopen(filename,"rb");
    	if(ptr==NULL){
        	dialogBox();
		setcolor(BLUE);
		outtextxy(240,170,filename);
		outtextxy(240,190,"Not Found");
		outtextxy(220,220,"Press any key..");
		getch();
    	}
    	else{
		setcolor(WHITE);
		dialogBox();
		setcolor(BLUE);
		outtextxy(240,190,"Loading . .");
		top=NULL;
        	while(!feof(ptr)){
           		fseek(ptr,index*sizeof(mk),SEEK_SET);
          		fread(&mk,sizeof(mk),1,ptr);
		   	if(feof(ptr))
				break;
           		pushToMem(mk.keyF,mk.keyD);
		   	index++;
        	}		
    	}
    fclose(ptr);
    return 0;
}

int playSong(){
	int stopKey;
	struct node *tmp;
	tmp=top;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	while(tmp!=NULL&&stopKey!=27){
		stopKey=0;
		if(kbhit())
			stopKey=getch();
		play(tmp->sf.keyF,tmp->sf.keyD);
		tmp=tmp->prev;
	}
	return 0;
}

/* delete third song */
int deleteC(){
	char ch;
	int req,i,count=0;
	FILE *ptr = fopen(mgList, "r");
	FILE *fp=fopen(tmpList,"w");
	if(ptr==NULL){
		outtextxy(240,180,"Error");
		outtextxy(220,220,mgList);
		getch();
		exit(1);
	}
	for(i=0;mgBuff[i]!='\0';i++)
		mgBuff[i]='\0';
	i=0;
	while(!feof(ptr)){
		ch=getc(ptr);
		if(ch=='>')
			count++;
		if(count>1){
			mgBuff[i]=ch;
			putc(mgBuff[i],fp);
		}
		i++;
	}
	fclose(ptr);
	fclose(fp);
	req=remove(fnameC);
	remove(mgList);
	rename(tmpList,mgList);
	dialogBox();
	if(req==0){
		dialogBox();
		outtextxy(240,190,"Deleted");
		outtextxy(220,220,"Press any key..");
		getch();
	}
	return 0;
}

/* delete fourth song */
int deleteD(){
	char ch;
	int req,i=0,count=0;
	FILE *ptr = fopen(mgList, "r");
	FILE *fp=fopen(tmpList,"w");
	if(ptr==NULL){
		outtextxy(240,180,"Error");
		outtextxy(240,220,mgList);
		getch();
		exit(1);
	}
	for(i=0;mgBuff[i]!='\0';i++)
		mgBuff[i]='\0';
	i=0;
	while(!feof(ptr)){
		ch=getc(ptr);
		if(ch=='>')
			count++;
		if(count==1||count==3){
			mgBuff[i]=ch;
			putc(mgBuff[i],fp);
		}
		i++;
	}
	fclose(ptr);
	fclose(fp);
	req=remove(fnameD);
	remove(mgList);
	rename(tmpList,mgList);
	if(req==0){
		dialogBox();
		outtextxy(240,190,"Deleted");
		outtextxy(220,220,"Press any key..");
		getch();
	}
	return 0;
}

/* delete fifth song */
int deleteE(){
	char ch;
	int req,i,count=0;
	FILE *ptr = fopen(mgList, "r");
	FILE *fp=fopen(tmpList,"w");
	if(ptr==NULL){
		outtextxy(240,180,"Error");
		outtextxy(240,220,mgList);
		getch();
		exit(1);
	}
	for(i=0;mgBuff[i]!='\0';i++)
		mgBuff[i]='\0';
	i=0;
	while(!feof(ptr)){
		ch=getc(ptr);
		if(ch=='>')
			count++;
		if(count==1||count==2){
			mgBuff[i]=ch;
			putc(mgBuff[i],fp);
		}
		i++;
	}
	fclose(ptr);
	fclose(fp);
	req=remove(fnameE);
	remove(mgList);
	rename(tmpList,mgList);
	if(req==0){
		dialogBox();
		outtextxy(240,190,"Deleted");
		outtextxy(220,220,"Press any key..");
		getch();
	}
	return 0;
}
