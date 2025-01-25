#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "findPath.h"
#include "actionsMenu.h" //#include "file.h", "my_struct.h", "printColorMap.h"

char Map[MAXSIZE][MAXSIZE];

int main(void) { //قلمرو بازیکن1 با C و حاده ها با R نمایش داده میشود
    srand (time (NULL) ) ;
    int size,value;
    int Vcount, Xcount, Ccount;
    int i, j, k;
    Ruler player1={0, 1, 0, 1, 5, 0}; //دارایی های اولیه بازیکنان
    Ruler player2={0, 1, 0, 1, 5, 0};
    char map1[MAXSIZE][MAXSIZE], map2[MAXSIZE][MAXSIZE];
    FILE *gameFile;
    
    gameFile = fopen("Game.txt", "r");
    if (!gameFile) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(gameFile,"%d",&size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            Map[i][j] = '1';
        }
    }

    fscanf(gameFile,"%d",&Ccount); //قرار گیری قلمرو ها
    Coordinates Castle[Ccount];
    fscanf(gameFile,"%d %d", &i, &j);
    Map[i - 1][j - 1] = 'C';
    Castle[0].x= i-1 ;
    Castle[0].y= j-1 ;
    for (k = 1; k < Ccount; k++) {
        fscanf(gameFile,"%d %d", &i, &j);
        Map[i - 1][j - 1] = 'c';
        Castle[k].x= i-1 ;
        Castle[k].y= j-1 ;
    }

    fscanf(gameFile,"%d",&Vcount); //قرار گیری روستا ها و نرخ تولید
    Coordinates Village[Vcount];
    Rates vRate[Vcount];
    for (k = 0; k < Vcount; k++) {
        fscanf(gameFile,"%d %d", &i, &j);
        Map[i - 1][j - 1] = 'V';
        fscanf(gameFile,"%d %d",&vRate[k].goldRate, &vRate[k].foodRate);
        Village[k].x = i-1;
        Village[k].y = j-1;
    }

    fscanf(gameFile,"%d",&Xcount);//قرار گیری خانه های مسدود
    for (k = 0; k < Xcount; k++) {
        fscanf(gameFile,"%d %d", &i, &j);
        Map[i - 1][j - 1] = 'X';
    }

    for (i = 0; i < size; i++) { //ارزش دادن به خانه های خالی با عدد تصادفی از1 تا 4
        for (j = 0; j < size; j++) {
            if (Map[i][j] == '1') {
                value = generate_number();
                Map[i][j]= value+'0';
            }
        }
    }
    colorMap(Map,size);
    copyMap(Map,map1,size); //شخصی سازی نقشه بازی برای هر بازیکن
    copyMap(Map,map2,size);

    int sw=1,menuResult;
    while(sw) {

        do {
            SeparatorLine('_',60);
            printf("player 1's turn\n");
            menuResult=Menu(map1,map2,Map,size,&player1, &player2 ,vRate,Village,'R');//فراخوانی تابع انتخاب حرکت
            if(menuResult==1) {
                player1.gold+=player1.goldrate;
                player1.food+=player1.foodrate;
            }
        }while(menuResult==0);
        if (menuResult==-1) {
            printf("PLAYER 1 WIN THE GAME!");
            sw=0;
        }
        else{
            do {
                SeparatorLine('_',60);
                printf("player 2's turn:\n");
                menuResult=Menu(map2,map1,Map,size,&player2,&player1, vRate,Village,'r');//فراخوانی تابع انتخاب حرکت
                if(menuResult==1) {
                    player2.gold+=player1.goldrate;
                    player2.food+=player1.foodrate;
                }
            }while(menuResult==0);
            if (menuResult==-1) {
                printf("PLAYER 2 WIN THE GAME!");
                sw=0;
            }
        }
    }
    fclose(gameFile);
}
