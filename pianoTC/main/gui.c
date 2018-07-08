
/*
	Graphical modules
*/
#include "GLOBAL.H"

/*piano key position on keyboard*/
char keyPos[]={"135680=qetyip]adghk;"};
char keyPos2[]={"2479-wruo[sfjl"};

/* initiate graph */
int testGraph(){
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if(errorcode != grOk){
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to Quit:");
		getch();
		return 1;
	}
	return 0;
}

/* Reload after Playing/Deleting */
int pReload(){
	cleardevice();
	drawMenuTab();
	drawSecondTab();
	setFiles();
	return 0;
}
/* Dialog Box*/
int dialogBox(){
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(205,155,405,255); //Shadow

	setfillstyle(SOLID_FILL,WHITE);
	bar(200, 150, 400, 250);

	setcolor(RED);
	rectangle(202, 152, 398, 248);
	return 0;
}

/* Display Introduction */
int introBox(){
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(210,150,430,330);
	setfillstyle(SOLID_FILL,WHITE);
	bar(220,160,420,320);

	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(250,190,380,240);

	setcolor(WHITE);
	outtextxy(280,210,"P I A N O");
	setcolor(GREEN);
	outtextxy(300,250,"in");
	setcolor(BLUE);
	outtextxy(290,270,"TURBO C");
	setcolor(RED);
	outtextxy(389,310,"v1.0");
	getch();
	delay(500);
	return 0;
}

/* Draw tab for mouse*/
int drawMenuTab(){
	setfillstyle(SOLID_FILL, LIGHTGRAY);	// canvas
	bar(0,20,getmaxx(),getmaxy()-20);

	setfillstyle(SOLID_FILL,DARKGRAY); 		//Shadow
	bar(22,37,112,72);
	bar(132,37,222,72);
	bar(242,37,332,72);
	bar(522,37,602,72);

	setfillstyle(SOLID_FILL,CYAN);
	bar(20, 35, 110, 70); 		//Main tab
	bar(130, 35, 220, 70); 		//Piano tile tab
	bar(240, 35, 330, 70);		//About tab
	setfillstyle(SOLID_FILL,RED);
	bar(520, 35, 600, 70); 		//exit

	setcolor(BLACK);
	rectangle(5,25,635,80);
	rectangle(5,90,635,455);

	outtextxy(35,50,"P L A Y");
	outtextxy(145,50,"O P E N");
	outtextxy(250,50,"A B O U T");
	outtextxy(535,50,"E X I T");
	return 0;
}

/* first tab / play tab */
void drawFirstTab(){
	int top=325,bot=425;
	int i,j=50;
	char ch[1];

	setcolor(WHITE);
	rectangle(22,37,108,68);      //tab selection

	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(17,302,627,432);
	setfillstyle(SOLID_FILL,BROWN);   //Background for the Tiles
	bar(15,300,625,430);

	setfillstyle(SOLID_FILL,WHITE);
	for(i=22;i<=592;i+=30){
		bar(i,top,j,bot);
		j+=30;
	}
	setfillstyle(SOLID_FILL,DARKGRAY);
	j=60;
	for(i=40;i<=580;i+=30){
		if(j==120||j==240||j==330||j==450||j==540){
			j+=30;
			continue;
		}
		bar(i,top,j,390);
		j+=30;
	}
	setcolor(RED);
	j=30;
	for(i=0;i<20;i++){
		sprintf(ch,"%c",keyPos[i]);
		outtextxy(j,410,ch);
		j+=30;
	}
	i=0;
	for(j=45;j<=585;j+=30){
		if(j==105||j==225||j==315||j==435||j==525)
			continue;
		sprintf(ch,"%c",keyPos2[i]);
		outtextxy(j,350,ch);
		i++;
	}
	setfillstyle(SOLID_FILL,RED);
}

/* Second Tab / open tab*/
void drawSecondTab(){
	setcolor(WHITE);
	rectangle(132,37,218,68);  //tab selection

	setfillstyle(SOLID_FILL,DARKGRAY);
	/* file list shadow */
	bar(32,152,352,182);
	bar(32,202,352,232);
	bar(32,252,352,282);
	bar(32,302,352,332);
	bar(32,352,352,382);
	/* play shadow */
	bar(402,152,482,182);
	bar(402,202,482,232);
	bar(402,252,482,282);
	bar(402,302,482,332);
	bar(402,352,482,382);
	/* delete shadow */

	bar(532,252,592,282);
	bar(532,302,592,332);
	bar(532,352,592,382);

	setfillstyle(SOLID_FILL, YELLOW);  //file selection
	bar(30,150,350,180);
	bar(30,200,350,230);
	bar(30,250,350,280);
	bar(30,300,350,330);
	bar(30,350,350,380);

	setfillstyle(SOLID_FILL, GREEN);  //play button
	bar(400,150,480,180);
	bar(400,200,480,230);
	bar(400,250,480,280);
	bar(400,300,480,330);
	bar(400,350,480,380);

	setfillstyle(SOLID_FILL, RED);	//delete button

	bar(530,250,590,280);
	bar(530,300,590,330);
	bar(530,350,590,380);

	setcolor(WHITE);
	outtextxy(410,162,"P L A Y");
	outtextxy(410,212,"P L A Y");
	outtextxy(410,262,"P L A Y");
	outtextxy(410,312,"P L A Y");
	outtextxy(410,362,"P L A Y");

	outtextxy(535,262,"Delete");
	outtextxy(535,312,"Delete");
	outtextxy(535,362,"Delete");
}

/* Third tab / about tab*/
void drawThirdTab(){
	setcolor(WHITE);
	rectangle(242,37,328,68);

	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(135,135,505,425);

	setfillstyle(SOLID_FILL,BROWN);
	bar(130,130,500,420);

	setcolor(WHITE);
	rectangle(132,132,498,418);
	outtextxy(250,170,"PIANO in TURBO C");
	outtextxy(270,210,"(March 2017)");
	outtextxy(280,230,"by Kromi");
	setcolor(BLUE);
	outtextxy(300,190,"v1.0");
}

/* Quit dialog box for mouse*/
int quitDialog(){
	setcolor(WHITE);
	rectangle(522,37,598,68);
	dialogBox();
	setcolor(BLUE);
	outtextxy(240,170,"Are You Sure ?");

	setfillstyle(SOLID_FILL,DARKGRAY);  //shadow
	bar(322,210,382,230);
	bar(220,210,282,230);
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,GREEN);
	bar(320,208,380,228);
	outtextxy(340,215,"N O");

	setfillstyle(SOLID_FILL,RED);
	bar(220,208,280,228);
	outtextxy(230,215,"Y E S");
	return 0;
}
