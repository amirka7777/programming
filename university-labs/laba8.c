#include <stdio.h>
#define n 3

int sum_mat(int matrix[n][n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void zap_mat(int matrix[n][n]) {
    printf("Введите матрицу (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        printf("Строка %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("---------------------------\n");
    printf("Исходная матрица: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    } 
    printf("---------------------------\n");
}

void posle_izm(int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        int sum_positive = 0;
        int count_positive = 0;
        
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                sum_positive += matrix[i][j];
                count_positive++;
            }
        }
        
        int average = 0;
        if (count_positive > 0) {
            average = sum_positive / count_positive;
        }
        
        for (int j = 0; j < n; j++) {
            matrix[i][j] += average;
        }
    }
}

void osi(int matrix[n][n]) {
    int arr[n*n];
    int count = 0;
    int negative_count = 0;
    
    printf("Элементы выше главной и побочной диагоналей:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j && i + j < n - 1) {
                arr[count] = matrix[i][j];
                printf("%d ", arr[count]);
                if (arr[count] < 0) {
                    negative_count++;
                }
                count++;
            }
        }
    }
    
    printf("\n");
    printf("Количество отрицательных элементов в полученном массиве: %d\n", negative_count);
    printf("---------------------------\n");
}

int main() {
    int matrix[n][n];
    
    zap_mat(matrix);
    int summa = sum_mat(matrix);
    printf("Сумма всех элементов матрицы = %d\n", summa);
    printf("---------------------------\n");
    
    printf("Матрица после изменения: \n");
    posle_izm(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------\n");
    osi(matrix);
    
}