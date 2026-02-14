#include "carsHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void ArrayFilling(Cars arr[]) {

    srand(time(NULL));

    const char *randModel[] = {"bmw", "merseders", "porsh", "gelik brabus", "lada", "rolls-roys", "tesla"};

    int year_min = 1999;
    int year_max = 2026;

    int power_min = 150;
    int power_max = 1000;

    int price_min = 1000000;
    int price_max = 9500000;

    for (int i = 0; i < N; i++) {
        int modelIndex = rand() % (sizeof(randModel) / sizeof(randModel[0]));
        strcpy(arr[i].model, randModel[modelIndex]);

        arr[i].year = year_min + rand() % (year_max - year_min + 1);
        arr[i].power = power_min + rand() % (power_max - power_min + 1);
        arr[i].price = price_min + rand() % (price_max - price_min + 1);
    }


}

void printArray(Cars carsArray[]) {
    for (int i = 0; i < N; i++) {
        printf("cars: %d, model: %s, year: %d, power: %d, price: %d\n", i + 1, carsArray[i].model, carsArray[i].year, carsArray[i].power, carsArray[i].price);
    }
}





int compare(Cars a, Cars b) {
    return a.year - b.year;
}



void bubbleSort(Cars arrayCars[], int (*compare)(Cars, Cars)) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (compare(arrayCars[j], arrayCars[j + 1]) > 0) {
                Cars temp = arrayCars[j];
                arrayCars[j] = arrayCars[j + 1];
                arrayCars[j + 1] = temp;
            }
        }   
    }

}
