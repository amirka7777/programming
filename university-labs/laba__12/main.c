#include "carsHeader.h"
#include <stdio.h>

int main() {

    Cars carsArray[N];
    
    ArrayFilling(carsArray);

    printf("массив до сортировки по году выпуска:\n");
    printArray(carsArray);

    printf("\n");

    printf("массив после сортировки по году выпуска:\n");
    bubbleSort(carsArray);
    printArray(carsArray);

}