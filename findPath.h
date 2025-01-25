//
// Created by mahsa on 1/3/2025.
//

#ifndef FINDPATH_H
#define FINDPATH_H

#endif //FINDPATH_H

#include <stdio.h>
#include "my_struct.h"//MAXSIZE=17




// تابع برای بررسی خانه‌های ایمن
int isSafe(char arr[][MAXSIZE],int size, int x, int y, int visited[][MAXSIZE]) {
    return (x >= 0 && x < size && y >= 0 && y < size && (arr[x][y] == '1' || arr[x][y]=='R') && !visited[x][y]);
}

// تابع flood fill برای علامت گذاری مسیر
int floodFillPath(char arr[][MAXSIZE],int size, int x, int y, int targetX, int targetY, int visited[][MAXSIZE]) {
    char temp;
    // اگر به هدف رسیدیم
    if (x == targetX && y == targetY) {
        return 1; // مسیر پیدا شد
    }

    // خانه فعلی را به عنوان بازدید شده علامت‌گذاری کنید
    visited[x][y] = 1;

    // تلاش برای حرکت در چهار جهت
    int rowDir[] = {1, -1, 0, 0};
    int colDir[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int newX = x + rowDir[i];
        int newY = y + colDir[i];

        // اگر حرکت به خانه جدید ایمن باشد
        if (isSafe(arr,size, newX, newY, visited)) {
            temp=arr[newX][newY];
            arr[newX][newY] ='R'; // علامت گذاری خانه عبوری با R
            if (floodFillPath(arr,size, newX, newY, targetX, targetY, visited)) {
                return 1; // اگر هدف پیدا شد
            }

            arr[newX][newY] =temp; // برگرداندن به حالت قبلی اگر هدف پیدا نشد
        }
    }

    return 0; // مسیر پیدا نشد
}

void findPath(char arr[][MAXSIZE],int size, int startX, int startY, int targetX, int targetY) {
    int visited[MAXSIZE][MAXSIZE] = {0}; // آرایه برای ثبت خانه‌های بازدید شده
    if (floodFillPath(arr,size, startX, startY, targetX, targetY, visited)) {
        //printf("Path found.\n");
    } else {
        printf("No path found.\n");
    }
}