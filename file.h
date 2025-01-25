//
// Created by mahsa on 12/5/2024.
//

#ifndef INC_1ST_PHASE_PRINTMAP_H
#define INC_1ST_PHASE_PRINTMAP_H

#endif //INC_1ST_PHASE_PRINTMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_struct.h"

void printMap(int size,char map[][MAXSIZE]){ //پرینت معمولی نقشه
    int i,j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("%c ",map[i][j]);}
        printf("\n");
    }
}

int generate_number () { // انتخاب عدد تصادفی از 1 تا 4 برای ارزش دادن به خانه ها
    const double probs[9] = {0.65, 0.25, 0.05, 0.05, 0, 0, 0, 0, 0};
    double cdf[9];
    cdf[0] = probs[0];
    for (int i = 1; i < 9; ++i) {
        cdf[i] = cdf[i - 1] + probs[i];
    }

    double rand_val =(double)rand() /RAND_MAX ;

    for (int i = 0; i < 9; ++i) {
        if (rand_val < cdf[i]) {
            return i + 1;
        }
    }
    return -1;
}

void SeparatorLine(char sep,int n) { // پرینت خط جدا کننده
    int i;
    for (i=0; i<n; i++)
        printf("%c",sep);
    printf("\n");
}

int CheckRoad(char Map[][MAXSIZE],int x,int y, char yourR,int size) { //چک کردن امکان جاده سازی در یک مختصات
    if (Map[x][y] !='1' && Map[x][y] !='2' && Map[x][y] !='3' && Map[x][y] !='4') return 0;
    int i;
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};
    char temp;
    char yourC;// enemyR, enemyC
    if(yourR == 'R') {
        yourC='C';
        //enemyC= 'c';
        //enemyR= 'r';
    }
    else {
        yourC='c';
        //enemyC='C';
        //enemyR='R';
    }
    for(i=0;i<4;i++) {
        if ((x+rowDir[i]<size && x+rowDir[i]>-1) && (y+colDir[i]<size && y+colDir[i]>-1)) temp=Map[x+rowDir[i]][y+colDir[i]];
        if(temp==yourC || temp==yourR) return 1;
        if (temp=='v') {
            int newX=x+rowDir[i];
            int newY=y+colDir[i];
            for(int j=0;j<4;j++) {
                if(Map[newX+rowDir[j]][newY+colDir[j]]==yourR) return 1;
            }
        }
    }
    return 0;
}

void CheckVillage(char Map1[][MAXSIZE],char Map2[][MAXSIZE],int x,int y,int *CgoldRate,int *CfoodRate,Coordinates villages[],Rates V[],int size) { // چک کردن فتح روستا
    int i,j;
    int newX,newY;
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};
    for(i=0;i<4;i++) {
        if (Map1[x+rowDir[i]][y+colDir[i]]=='V' && (x+rowDir[i]<size && x+rowDir[i]>-1) && (y+colDir[i]<size && y+colDir[i]>-1)) {
            newX=x+rowDir[i];
            newY=y+colDir[i];
            Map1[newX][newY]='v'; //تغییر نقشه هر دو بازیکن
            Map2[newX][newY]='v';
            for(j=0; villages[j].x!=newX ||villages[j].y!=newY;j++);
            *CgoldRate+=V[j].goldRate;
            *CfoodRate+=V[j].foodRate;
            V[j].goldRate=0 ,V[j].foodRate=0;
            return;
        }
    }
}

void copyMap(const char Map[][MAXSIZE],char Map2[][MAXSIZE],int size) {
    int i,j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            Map2[i][j]=Map[i][j];
        }
    }
}


