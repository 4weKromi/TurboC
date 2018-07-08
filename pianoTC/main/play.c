/* 
	Piano modules
*/
#include "GLOBAL.H"
extern char fnameA[];
extern char fnameB[];
extern char fnameC[];
extern char fnameD[];
extern char fnameE[];
extern char mgList[];
extern char buff[];

/* MG data structure */
struct keyData{
	float keyF;
	float keyD;
}mk2;

/*34 Keys for runtime play*/
float keyFreq[]={0.0,130.81,138.59,146.83,155.56,164.81,174.61,184.99,195.99,207.65,
	220,233.08,246.94,261.62,277.18,293.66,311.12,329.62,349.22,369.99,391.99,415.30,
	440,466.16,493.83,523.25,554.36,587.32,622.25,659.25,698.45,739.98,783.99,830.60,
	880};

/* play using frequency and delay*/
void play(float key,float del){
	 sound(key);
	 delay(del);
	 nosound();
}

/* play first song */
int startA(){
	loadFile(fnameA);
	setcolor(WHITE);
	rectangle(402,152,478,178);
	dialogBox();
	setcolor(BLUE);
	outtextxy(240,190,"Playing . .");
	outtextxy(220,210,"Press Esc key to stop");
	playSong();
	return 0;
}

/* play second song */
int startB(){
	loadFile(fnameB);
	setcolor(WHITE);
	rectangle(402,202,478,228);
	dialogBox();
	setcolor(BLUE);
	outtextxy(240,190,"Playing . .");
	outtextxy(220,210,"Press Esc key to stop");
	playSong();
	return 0;
}

/* play third song */
int startC(){
	loadFile(fnameC);
	setcolor(WHITE);
	rectangle(402,252,478,278);
	dialogBox();
	setcolor(BLUE);
	outtextxy(240,190,"Playing . .");
	outtextxy(220,210,"Press Esc key to stop");
	playSong();
	return 0;
}

/* play fourth song */
int startD(){
	loadFile(fnameD);
	setcolor(WHITE);
	rectangle(402,302,478,328);
	dialogBox();
	setcolor(BLUE);
	outtextxy(240,190,"Playing . .");
	outtextxy(220,210,"Press Esc key to stop");
	playSong();
	return 0;
}

/* play fifth song */
int startE(){
	loadFile(fnameE);
	setcolor(WHITE);
	rectangle(402,352,478,378);
	dialogBox();
	setcolor(BLUE);
	outtextxy(240,190,"Playing . .");
	outtextxy(220,210,"Press Esc key to stop");
	playSong();
	return 0;
}

/* Play Piano */
int runtimePlay(){
	int i,ch,j=0;
	char newF[64];
	float buffer[4096];
	setcolor(RED);
	outtextxy(40,170,"Press [Esc] to stop..");
	while(ch!=27){
		setcolor(RED);
		ch=getch();
		if(ch==49){
			outtextxy(30,315,"C");
			play(keyFreq[1],200);
			buffer[j]=keyFreq[1];
		}
		else if(ch==50){
			outtextxy(45,310,"C#");
			play(keyFreq[2],200);
			buffer[j]=keyFreq[2];
		}
		else if(ch==51){
			outtextxy(60,315,"D");
			play(keyFreq[3],200);
			buffer[j]=keyFreq[3];	
		}
		else if(ch==52){
			outtextxy(75,310,"D#");
			play(keyFreq[4],200);
			buffer[j]=keyFreq[4];
		}
		else if(ch==53){
			outtextxy(90,315,"E");
			play(keyFreq[5],200);
			buffer[j]=keyFreq[5];
		}
		else if(ch==54){
			outtextxy(120,315,"F");
			play(keyFreq[6],200);
			buffer[j]=keyFreq[6];
		}
		else if(ch==55){
			outtextxy(135,310,"F#");
			play(keyFreq[7],200);
			buffer[j]=keyFreq[7];
		}
		else if(ch==56){
			outtextxy(150,315,"G");
			play(keyFreq[8],200);
			buffer[j]=keyFreq[8];
		}
		else if(ch==57){
			outtextxy(165,310,"G#");
			play(keyFreq[9],200);
			buffer[j]=keyFreq[9];
		}
		else if(ch==48){
			outtextxy(180,315,"A");
			play(keyFreq[10],200);
			buffer[j]=keyFreq[10];
		}
		else if(ch==45){
			outtextxy(195,310,"A#");
			play(keyFreq[11],200);
			buffer[j]=keyFreq[11];
		}
		else if(ch==61){
			outtextxy(210,315,"B");
			play(keyFreq[12],200);
			buffer[j]=keyFreq[12];
		}
		else if(ch==113){
			outtextxy(240,315,"C");
			play(keyFreq[13],200);
			buffer[j]=keyFreq[13];
		}
		else if(ch==119){
			outtextxy(255,310,"C#");
			play(keyFreq[14],200);
			buffer[j]=keyFreq[14];
		}
		else if(ch==101){
			outtextxy(270,315,"D");
			play(keyFreq[15],200);
			buffer[j]=keyFreq[15];
		}
		else if(ch==114){
			outtextxy(285,310,"D#");
			play(keyFreq[16],200);
			buffer[j]=keyFreq[16];
		}
		else if(ch==116){
			outtextxy(300,315,"E");
			play(keyFreq[17],200);
			buffer[j]=keyFreq[17];
		}
		else if(ch==121){
			outtextxy(330,315,"F");
			play(keyFreq[18],200);
			buffer[j]=keyFreq[18];
		}
		else if(ch==117){
			outtextxy(345,310,"F#");
			play(keyFreq[19],200);
			buffer[j]=keyFreq[19];
		}
		else if(ch==105){
			outtextxy(360,315,"G");
			play(keyFreq[20],200);
			buffer[j]=keyFreq[20];
		}
		else if(ch==111){
			outtextxy(375,310,"G#");
			play(keyFreq[21],200);
			buffer[j]=keyFreq[21];
		}
		else if(ch==112){
			outtextxy(390,315,"A");
			play(keyFreq[22],200);
			buffer[j]=keyFreq[22];
		}
		else if(ch==91){
			outtextxy(405,310,"A#");
			play(keyFreq[23],200);
			buffer[j]=keyFreq[23];
		}
		else if(ch==93){
			outtextxy(420,315,"B");
			play(keyFreq[24],200);
			buffer[j]=keyFreq[24];
		}
		else if(ch==97){
			outtextxy(450,315,"C");
			play(keyFreq[25],200);
			buffer[j]=keyFreq[25];
		}
		else if(ch==115){
			outtextxy(465,310,"C#");
			play(keyFreq[26],200);
			buffer[j]=keyFreq[26];
		}
		else if(ch==100){
			outtextxy(480,315,"D");
			play(keyFreq[27],200);
			buffer[j]=keyFreq[27];
		}
		else if(ch==102){
			outtextxy(495,310,"D#");
			play(keyFreq[28],200);
			buffer[j]=keyFreq[28];
		}
		else if(ch==103){
			outtextxy(510,315,"E");
			play(keyFreq[29],200);
			buffer[j]=keyFreq[29];
		}
		else if(ch==104){
			outtextxy(540,315,"F");
			play(keyFreq[30],200);
			buffer[j]=keyFreq[30];
		}
		else if(ch==106){
			outtextxy(555,310,"F#");
			play(keyFreq[31],200);
			buffer[j]=keyFreq[31];
		}
		else if(ch==107){
			outtextxy(570,315,"G");
			play(keyFreq[32],200);
			buffer[j]=keyFreq[32];
		}
		else if(ch==108){
			outtextxy(585,310,"G#");
			play(keyFreq[33],200);
			buffer[j]=keyFreq[33];
		}
		else if(ch==59){
			outtextxy(600,315,"A");
			play(keyFreq[34],200);
			buffer[j]=keyFreq[34];
		}
		setfillstyle(SOLID_FILL,BROWN);
		bar(22,305,610,323);
		j++;
	}
	dialogBox();
	outtextxy(260,160,"SAVE ?");
	setfillstyle(SOLID_FILL,DARKGRAY);  //shadow
	bar(322,210,382,230);
	bar(220,210,282,230);
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,GREEN);
	bar(320,208,380,228);
	outtextxy(340,215,"N O");

	setfillstyle(SOLID_FILL,GREEN);
	bar(220,208,280,228);
	outtextxy(230,215,"Y E S");
	i=dialogMouse();
	if(i==5){
		FILE *ptr;
		FILE *fp;
		char _s[1];
		dialogBox();
		for(j=0;buff[j]!='\0';j++)
			buff[j]='\0';
		j=0;
		outtextxy(240,170,"Enter Filename : ");
		while(ch!=13){
			ch=getch();
			sprintf(_s,"%c",ch);
			outtextxy(220+i,200,_s);
			i+=10;
			if((ch>44&&ch<58)||(ch>64&&ch<122)){
				buff[j]=(char)ch;
				j++;
			}
			if(ch==8){
				dialogBox();
				for(j=0;buff[j]!='\0';j++)
					buff[j]='\0';
				dialogBox();
				j=0;
				outtextxy(220,160,"Cleared !");
				outtextxy(220,180,"Type again ");
				getch();
				dialogBox();
				outtextxy(240,170,"Enter Filename : ");
				i=0;
			}
		}
		j=0;
		sprintf(newF,"%s.mg",buff);
		remove(newF);
		ptr=fopen(newF,"ab");
		if(ptr==NULL){
			dialogBox();
			outtextxy(220,180,"Error Saving");
			outtextxy(220,200,newF);
			getch();
			startPiano();
		}
		while(buffer[j]!='\0'){
			mk2.keyF=buffer[j];
			mk2.keyD=180;
			fwrite(&mk2,sizeof(mk2),1,ptr);
			j++;
		}
		fclose(ptr);
		dialogBox();
		outtextxy(240,190,"Save to.. 1/2/3 : ");
		ch=getch();
		if(ch==49)
			deleteC();
		else if(ch==50)
			deleteD();
		else
			deleteE();
		fp=fopen(mgList,"a");
		fprintf(fp,">%s;",newF);
		fclose(fp);
		dialogBox();
		outtextxy(240,180,newF);
		outtextxy(240,220,"Saved !");
		getch();
		startPiano();
	}
	else{
		for(j=0;buffer[j]!='\0';j++)
			buffer[j]='\0';
		startPiano();
	}
	return 0;
}

/* Play Page */
int startPiano(){
	cleardevice();
	drawMenuTab();
	drawFirstTab();
	outtextxy(40,150,"Press any key to start..");
	funcMouse(playMouse());
	mouseHide();
	runtimePlay();
	return 0;
}

/* open page*/
int openTab(){
	cleardevice();
	drawMenuTab();
	drawSecondTab();
	setFiles();
	openMouse();
	return 0;
}

/* About Page*/
int aboutTab(){
	cleardevice();
	drawMenuTab();
	drawThirdTab();
	funcMouse(aboutMouse());
	return 0;
}

/* quitInterface for Page*/
int quitTab(){
	quitDialog();
	funcMouse(dialogMouse());
	return 0;
}
