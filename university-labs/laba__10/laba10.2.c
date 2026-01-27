#include "laba10.1.h"

int point_definition(struct Point p) {
    if (p.x == 0 && p.y == 0) {
        return 0;
    }
    else if (p.x > 0 && p.y > 0) {
        return 1;
    }
    else if (p.x < 0 && p.y > 0) {
        return 2;
    }
    else if (p.x < 0 && p.y < 0) {
        return 3;
    }
    else {
        return 4;
    }
}

void quarter_output(struct Point p, int point_number) {
    int definition = point_definition(p);
    printf("Координаты точки %d (%.1f, %.1f): ", point_number, p.x, p.y);
    switch (definition)
    {
    case 0: printf("лежит на оси\n");
        break;
    case 1: printf("лежит в 1 четверти\n");
        break;
    case 2: printf("лежит во 2 четверти\n");
        break;
    case 3: printf("лежит в 3 четверти\n");
        break;
    case 4: printf("лежит в 4 четверти\n");
        break;
        
    default: printf("проблема определения положения точки\n");
        break;
    }
}