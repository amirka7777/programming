#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

pthread_mutex_t parent_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t child_mutex = PTHREAD_MUTEX_INITIALIZER;

int **A, **B, **C;
int N;

char *strings[4][3] = {
    {"мимими", "мямямя", "я поток 0"},
    {"кукуку", "кикики", "я поток 1"},
    {"пипипи", "пупупу", "я поток 2"},
    {"ририри", "рарара", "я поток 3"}
};

int **memory_alloc(int N) {
    int **matrix = malloc(N * sizeof(int *));
    for (int i = 0 ; i < N; i++) {
        matrix[i] = malloc(N * sizeof(int));
    }

    return matrix;
}

void print_matrix(int n, int **matrix) {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(int **matrix, int N) {
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1;
        }
    }
}

void *mul_matrix(void *args) {

    int *range = (int *) args;
    int start = range[0];
    int end = range[1];

    for (int i = start; i < end; i++) { 
        for (int j = 0; j < N; j++) { 
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    free(range);
    return NULL;

}


void *sleep_sort(void *args) {
    
    int value = *(int *)args;
    sleep(value);
    printf("%d ", value);
    return NULL;

}

void last_message(void *args) {

    printf("Дочерний поток завершает свою работу!\n");

}

void last_message_strings(void *args) {
    int *thread_num = (int *)args;
    printf("Поток %d завершает свою работу\n", (*thread_num) + 1);
}

void *message_from_thread(void *args) {

    pthread_cleanup_push(last_message, NULL);

    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&child_mutex);
        printf("Сообщение от дочернего потока %d\n", i);
        pthread_mutex_unlock(&parent_mutex);
    }

    pthread_cleanup_pop(1);
    return NULL;

}

void *print_strings(void *args) {


    int thread_number = *(int *)args;
    pthread_cleanup_push(last_message_strings, args);

    for (int i = 0; i < 3; i++ ) {
        printf("Поток %d: %s\n", thread_number + 1, strings[thread_number][i]);
        sleep(2);

    }

    pthread_cleanup_pop(1);

    return NULL;

}

int main(int arg, char *args[]) {

    if (arg != 3) {
        printf("Ошибка в кол-ве аргументов (<размер матрицы> <кол-во потоков>)\n");
        return 1;
    }

    pthread_t child_thread;
    pthread_mutex_lock(&child_mutex);

    int res = pthread_create(&child_thread, NULL, message_from_thread, NULL);
    if (res != 0) {
        printf("Ошибка при создании с потока");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&parent_mutex);
        printf("Основной поток %d\n", i);
        pthread_mutex_unlock(&child_mutex);

    }
    pthread_join(child_thread, NULL);


    pthread_t threads[4];
    int threads_numbers[4];

    for (int i = 0; i < 4; i++) {
        threads_numbers[i] = i;
        pthread_create(&threads[i], NULL, print_strings, &threads_numbers[i]);
    }

    sleep(2);

    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    int n;
    int numbers[MAX_SIZE];
    printf("\nВведите количество элементов (не более %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE) {
        printf("Ошибка: 1 <= n <= %d \n", MAX_SIZE);
        return 1;
    }

    printf("Введите %d чисел типа int:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    pthread_t threads_sort[n];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads_sort[i], NULL, sleep_sort, &numbers[i]);
    }

    printf("\nМассив после SleepSort: ");
    for (int i = 0; i < n; i++) {
        pthread_join(threads_sort[i], NULL);
    }
    printf("\n");

    N = atoi(args[1]);
    int thread_count = atoi(args[2]);

    A = memory_alloc(N);
    B = memory_alloc(N);
    C = memory_alloc(N);

    fill_matrix(N, A);
    fill_matrix(N, B);

    if (N <= 5) {
        print_matrix(N, A);
        print_matrix(N, B);
    }

    struct timespec start_time, end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    pthread_t threads_matrix[thread_count];
    int all_rows = N / thread_count;
    int remainder_rows = N % thread_count;
    int start = 0;

    for (int p = 0; p < thread_count; p++) {
        int end = start + all_rows;

        if (p == thread_count - 1) {
            end += remainder_rows;
        }

        int *range = malloc(2 * sizeof(int));
        range[0] = start;
        range[1] = end;
        pthread_create(&threads_matrix[p], NULL, mul_matrix, range);

        start = end;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads_matrix[i], NULL);
    }


    clock_gettime(CLOCK_MONOTONIC, &end_time);


    if (N <= 5) {
        print_matrix(N, C);
    }

    free_matrix(A, N);
    free_matrix(B, N);
    free_matrix(C, N);


    double time_sec = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
    printf("Время выполнения программы = %.2f\n", time_sec);
 
}