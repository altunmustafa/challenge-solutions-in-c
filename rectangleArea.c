/* 
 * @name Rectangle Area
 * @brief Calculate rectangle area with a string expression
 *        Example: (0,0),(0,3),(2,3),(2,0) return 3*2=6
 *              or (0,0),(2,3),(0,3),(2,0) return 3*2=6
 * @file rectangleArea.c
 * @version 0.1
 * @author Mustafa Altun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int x,y;
}point_t;

typedef struct{
    point_t p[4];
}rectangle_t;

int rectangleArea(char *str){
    char *x, *y;
    int xLen, yLen;
    rectangle_t rect;

    x = strtok(str, "(,)");
    y = strtok(NULL, "(,)");

    rect.p[0].x = atoi(x);
    rect.p[0].y = atoi(y);

    for(int i=1; i<4; i++){
        x = strtok(NULL, "(,)");
        y = strtok(NULL, "(,)");

        rect.p[i].x = atoi(x);
        rect.p[i].y = atoi(y);
    }

    xLen = ((rect.p[0].x - rect.p[1].x) != 0) ? abs(rect.p[0].x - rect.p[1].x) : abs(rect.p[0].x - rect.p[2].x);
    yLen = ((rect.p[0].y - rect.p[1].y) != 0) ? abs(rect.p[0].y - rect.p[1].y) : abs(rect.p[0].y - rect.p[2].y);

    printf("%d, %d\n", xLen, yLen);

    return xLen*yLen;
}

int main(){
    char str[] = "(0,0),(0,3),(2,3),(2,0)";
    
    printf("%d", rectangleArea(str));
    return 0;
}