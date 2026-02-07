#include "carsHeader.h"
#include <stdio.h>
#include <sys/time.h>

int main() {

    Cars carsArray[N];
    struct timeval start, end;
    long seconds, microSeconds;
    
    ArrayFilling(carsArray);

    printf("массив до сортировки по году выпуска:\n");
    printArray(carsArray);

    printf("\n");

    printf("массив после сортировки по году выпуска:\n");
    bubbleSort(carsArray);
    printArray(carsArray);
    printf("\n");

    printf("подсчет время выполнения сортировки:\n");
    gettimeofday(&start, NULL);

    bubbleSort(carsArray);

    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microSeconds = end.tv_usec - start.tv_usec;

    double total_seconds = seconds + microSeconds / 1000000.0;

    printf("время выполнения функции (с): %.5f \n", total_seconds);
}