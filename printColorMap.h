//
// Created by mahsa on 1/4/2025.
//

#ifndef PRINTCOLORMAP_H
#define PRINTCOLORMAP_H

#endif //PRINTCOLORMAP_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "my_struct.h"
void setTextColor(int textColor, int backColor) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

void colorMap(char arr[][MAXSIZE],int size) {
    int i,j;
    for(i=0;i<size;i++) {
        for(j=0;j<size;j++) {
            if (arr[i][j]=='C' || arr[i][j]=='R') setTextColor(1,0);
            else if(arr[i][j]=='c' || arr[i][j]=='r') setTextColor(5,0);
            else if (arr[i][j]=='X') setTextColor(4,0);
            else if(arr[i][j]=='V') setTextColor(2,0);
            else if (arr[i][j]=='v') setTextColor(3,0);
            else if (arr[i][j]=='1' || arr[i][j]=='2' || arr[i][j]=='3' || arr[i][j]=='4') setTextColor(6,0);
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
    setTextColor(7,0);
}