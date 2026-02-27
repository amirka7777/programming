#include "laba10.1.h"




int main() {
    int N;
    printf("Введите количество точек: \n");
    scanf("%d", &N);
    struct Point points[N];
    for (int i = 0; i < N; i++) {
        printf("Введите координаты точки %d (x, y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    printf("определение четверти: \n");
    for(int i = 0; i < N; i ++) {
        quarter_output(points[i], i + 1);
    }
}
