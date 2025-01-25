//
// Created by mahsa on 12/14/2024.
//

#ifndef INC_1ST_PHASE_MY_STRUCT_H
#define INC_1ST_PHASE_MY_STRUCT_H

typedef struct {
    int x, y;
} Coordinates;

typedef struct {
    int soldiers;
    int goldrate;
    int foodrate;
    int workers;
    int gold;
    int food;
}Ruler;

typedef struct {
    int goldRate,foodRate;
} Rates;


#endif //INC_1ST_PHASE_MY_STRUCT_H

#define MAXSIZE 17