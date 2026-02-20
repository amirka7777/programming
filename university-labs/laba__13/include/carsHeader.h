#ifndef _CARS_FUNCTION_H
#define _CARS_FUNCTION_H

#define N 5


typedef struct {

    char model[50];
    int year;
    int power;
    int price;

} Cars;

int compare(Cars a, Cars b);
void ArrayFilling(Cars arr[]);
void printArray(Cars carsArray[]);
void bubbleSort(Cars arrayCars[], int (*comapre)(Cars, Cars));




#endif