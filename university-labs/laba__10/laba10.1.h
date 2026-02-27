#ifndef POINT_FUNCTIONS_H
#define POINT_FUNCTIONS_H

#include <stdio.h>

struct Point {
    double x;
    double y;
};

int point_definition(struct Point p);
void quarter_output(struct Point p, int point_number);

#endif