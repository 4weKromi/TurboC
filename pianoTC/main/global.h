
/*
	Headers
*/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

/* GUI */
int testGraph();
int startPiano();
int openTab();
int aboutTab();
int quitTab();
void drawFirstTab();
void drawSecondTab();
void drawThirdTab();

/* MOUSE */
int initMouse();
void showMousePtr();
void mousehide();
void getMousePos();
void setMousePos();
int dialogMouse();
int playMouse();
int aboutMouse();
void funcMouse();
void openMouse();

/* FILE OPERATIONS */
int setFiles();
int pushToMem(float k, float d);
int loadFile(char filename[]);
int playSong();
int deleteC();
int deleteD();
int deleteE();

/* PLAYER */
void play(float key, float del);
int runtimePlay();
int startA();
int startB();
int startC();
int startD();
int startE();

#endif
