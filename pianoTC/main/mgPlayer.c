/*
  mgPlayer v0.1 by 4wekromi (march 2017)
  -plays music.mg files
*/
#include <stdio.h>
#include <conio.h>
#include <dos.h>

char fnameA[]={"OdeToJoy-LudwigVanBeethoven.mg"};
int pushToMem(float k,float d);

struct keyData{
	float keyF;
	float keyD;
}mk;

void play(float key,float del){
     sound(key);
     delay(del);
     nosound();
}

struct node{
    struct keyData sf;
    struct node *next;
	  struct node *prev;
}*top;

int loadFile(char filename[]){
    int index=0;
    FILE *ptr=fopen(filename,"rb");
    if(ptr==NULL){   
	printf(" File %s not found",filename);
        return 1;
    }
    else{
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
int playSong(){
	struct node *tmp;
	tmp=top;
	while(tmp->next!=NULL)
		tmp=tmp->next;
	while(tmp!=NULL){
		play(tmp->sf.keyF,tmp->sf.keyD);
		tmp=tmp->prev;
	}
	return 0;
}

int main(){
	loadFile(fnameA);
	playSong();
	printf(" Done..");
	getch();
	return 0;
}
