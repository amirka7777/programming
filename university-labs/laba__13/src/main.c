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
    bubbleSort(carsArray, compare);
    printArray(carsArray);
    printf("\n");

    printf("подсчет время выполнения сортировки:\n");
    gettimeofday(&start, NULL);

    bubbleSort(carsArray, compare);

    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microSeconds = end.tv_usec - start.tv_usec;

    double total_seconds = seconds + microSeconds / 1000000.0;


    printf("время выполнения функции (с): %.5f \n", total_seconds);

    printf("\n");
    printf("размер данных:\n");

    size_t one_car = sizeof(Cars);
    size_t total_carsArray = sizeof(carsArray);

    printf("размер одной структуры: %zu байт\n", one_car);
    printf("размер всей структуры: %zu байт\n", total_carsArray);
}