#include <stdio.h>
#include <string.h>


typedef struct {
    char name[100];
    char id[100];
    char level[500];
} Staff;


int searchUserById() {
    FILE *base = fopen("database.dat", "rb");
    if (base == NULL) {
        printf("ошибка: не удалость считать файл database.dat");
        return 1;
    }

    Staff worker;
    char searchId[15];
    int found = 0;

    printf("введите ID желаемого работника: ");
    scanf("%s", &searchId);
    while(fread(&worker, sizeof(Staff), 1, base) == 1) {
        if (strcmp(worker.id, searchId) == 0) {
            printf("ИНФОРМАЦИЯ О СОТРУДНИКЕ:\n");
            printf("name = %s\n", worker.name);
            printf("id = %s\n", worker.id);
            printf("level = %s\n", worker.level);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("ошибка: работник с таким id отсутствует\n");
    }
    fclose(base);
    return 0;
}


void compress() {

    FILE *input = fopen("database.dat", "rb");
    if (input == NULL) {
        printf("ошибка: не удалось открыть файл database.dat\n");
        return;
    }
    FILE *output = fopen("database.rle", "wb");
    if (output == NULL) {
        printf("ошибка: не удалось открыть файл database.rle\n");
        fclose(input);
        return;
    }

    unsigned char current_byte;
    unsigned char prev_byte;
    unsigned char count = 1;

    while (fread(&current_byte, 1, 1, input)) {

        if (current_byte == prev_byte && count < 255) {
            count++;
        } else {
            fwrite(&count, 1, 1, output);
            fwrite(&prev_byte, 1, 1, output);

            prev_byte = current_byte;
            count = 1;
            
        }

    }

    fwrite(&count, 1, 1, output);
    fwrite(&prev_byte, 1, 1, output);

    fclose(input);
    fclose(output);
}

void decompress() {

    FILE *input = fopen("database.rle", "rb");
    if (input == NULL) {
        printf("ошибка: не удалось прочитать database.rle\n");
        return;
    }

    FILE *output = fopen("database_decompressed.dat", "wb");
    if (output == NULL) {
        printf("ошибка: не удалось прочитать database_decompressed.dat\n");
        fclose(input);
        return;
    }

    unsigned char count;
    unsigned char value;

    while (fread(&count, 1, 1, input)) {

        if (fread(&value, 1, 1, input)) {
            for (int i = 0; i < count; i++) {
                fwrite(&value, 1,1, output);
            }
        }

    }

    fclose(output);
    fclose(input);
}

void print_info() {

    FILE *file;
    long compressed_size;
    long origin_size;

    file = fopen("database.dat", "rb");
    if (file == NULL) {
        printf("ошибка: не удалось прочитать database.dat\n");
        return;
    }


    fseek(file, 0, SEEK_END);
    origin_size = ftell(file);
    fclose(file);

    file = fopen("database.rle", "rb");
    if (file == NULL) {
        printf("ошибка: не удалось открыть файл database.rle\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    compressed_size = ftell(file);
    fclose(file);

    printf("размер файла до %ld байт\n", origin_size);
    printf("размер файла после %ld байт\n", compressed_size);

    printf("сжатия произошло на %.2f%%\n", 100.0 - (compressed_size * 100.0 / origin_size));

}

void compress_png() {

    FILE *input = fopen("images.png", "rb");
    if (input == NULL) {
        printf("ошибка: не удалось открыть файл images.png\n");
        return;
    }

    FILE *output = fopen("images.rle", "wb");
    if (output == NULL) {
        printf("ошибка: не удалось открыть файл images.rle\n");
        return;
    }

    unsigned char prev, current;
    unsigned char count = 1;
    fread(&prev, 1, 1, input);

    while (fread(&current, 1, 1, input)) {
        if (current == prev && count < 255) {
            count++;
        } else {
            fwrite(&count, 1, 1, output);
            fwrite(&prev, 1, 1, output);
            prev = current;
            count = 1;
        }
    }

    fwrite(&count, 1, 1, output);
    fwrite(&prev, 1, 1, output);

    fclose(input);
    fclose(output);

}

void decompress_png() {

    FILE *input = fopen("images.rle", "rb");
    if (input == NULL) {
        printf("ошибка: не удалось прочитать database.rle\n");
        return;
    }

    FILE *output = fopen("images_dec.png", "wb");
    if (output == NULL) {
        printf("ошибка: не удалось прочитать database_decompressed.dat\n");
        fclose(input);
        return;
    }

    unsigned char count;
    unsigned char value;

    while (fread(&count, 1, 1, input)) {

        if (fread(&value, 1, 1, input)) {
            for (int i = 0; i < count; i++) {
                fwrite(&value, 1,1, output);
            }
        }

    }

    fclose(output);
    fclose(input);
}

void print_info_png() {

    FILE *file;
    long compressed_size;
    long origin_size;
    long dec_size;

    file = fopen("images.png", "rb");
    if (file == NULL) {
        printf("ошибка: не удалось прочитать images.png\n");
        return;
    }


    fseek(file, 0, SEEK_END);
    origin_size = ftell(file);
    fclose(file);

    file = fopen("images.rle", "rb");
    if (file == NULL) {
        printf("ошибка: не удалось открыть файл images.rle\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    compressed_size = ftell(file);
    fclose(file);

    printf("\nразмер файла до %ld байт\n", origin_size);
    printf("размер файла после %ld байт\n", compressed_size);

    printf("сжатия произошло на %.2f%%\n", 100.0 - (compressed_size * 100.0 / origin_size));

    file = fopen("images_dec.png", "rb");
    if (file == NULL) {
        printf("ошибка: не удалось открыть файл images_dec.png\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    dec_size = ftell(file);
    fclose(file);

    if (origin_size == dec_size) {
        printf("dec = origin\n");
    }

}

int main(int arguments, char *args[]) {

    if (arguments != 2) {
        printf("Ошибка: неверное количество аргументов\n");
        return 1;
    }

    FILE *file = fopen(args[1], "r");
    if (file == NULL) {
        printf("Ошибка: не получилось открыть файл %s\n", args[1] );
        return 1;
    }

    Staff myStaff[15];

    char line[256];

    int count = 0;

    printf("===КОМПАНИЯ АМИРА===\n");
    while(fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\n")] = 0;

        char *name = strtok(line, ";");

        char *id = strtok(NULL, ";");

        char *level = strtok(NULL, ";");


        printf("[%d] name: %s, id: %s, level: %s\n", count + 1, name, id, level);
        strcpy(myStaff[count].name, name);
        strcpy(myStaff[count].id, id);
        strcpy(myStaff[count].level, level);
        count++;
    }
    
    fclose(file);

    FILE *dat = fopen("database.dat", "wb");
    if (dat == NULL) {
        printf("Ошибка: не получилось открыть файл database.dat\n");
        return 1;
    }

    fwrite(myStaff, sizeof(Staff), count, dat);
    fclose(dat);

    searchUserById();
    compress();
    print_info();
    decompress();

    compress_png();
    print_info_png();
    decompress_png();

}