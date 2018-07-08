/*
	Piano in Turbo C by 4weKromi
*/

#include "GLOBAL.H"

/*global variables*/
/* Holds name of files, loaded from mglist.li */
char fnameA[]={"OdeToJoy-LudwigVanBeethoven.mg"};
char fnameB[]={"CanonInD-JohannPachebel.mg"};
char fnameC[32];
char fnameD[32];
char fnameE[32];
	
/*Temporary mg list*/
char tmpList[]={"temp.li"};

/* Holds the .mg list*/
char mgArr[3][32];

/* Holds .mg filename to be displayed*/
char mgBuff[96];

/*File which contains user-saved mg list*/
char mgList[]={"mgList.li"};

/*temporarily holds file names*/
char buff[32];


/* starts the program */
int main(){
	if(!testGraph()){
		introBox();
		startPiano();
	}
	else
		exit(1);
	return 0;
}
