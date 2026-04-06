#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Room {

    char name[50];
    int level;
    int number;
    int resolution;

    struct Room *next;
    struct Room *prev;
    struct Room *down;

} Room;

Room *createNode(char name[], int level, int number, int resolution) {

    Room *newRoom = (Room *)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->level = level;
    newRoom->number = number;
    newRoom->resolution = resolution;

    newRoom->next = NULL;
    newRoom->prev = NULL;
    newRoom->down = NULL;

    return newRoom;

}


Room *insertAtEnd(Room *head, char name[], int level, int number, int resolution) {

    Room *newNode = createNode(name, level, number, resolution);

    if (head == NULL) {
        return newNode;
    }

    Room *current = head;

    while (current->next != NULL) {

        current = current->next;

    }

    current->next = newNode;
    newNode->prev = current;

    return head;

}


Room *printlist(Room *head) {

    Room *current = head;

    while (current != NULL) {

        printf("name %s level %d number %d resolution %d\n", current->name, current->level, current->number, current->resolution);
        current = current->next;
        
    }

    return head;

}


Room *ListsFilling(Room *head, int n){

    srand(time(NULL));

    const char *roomList[] = {"room1", "room2", "room3", "room4", "room5"};

    int min = 1;
    int max = 10;

    for (int i = 0; i < n; i++ ) {
        Room *newNode = (Room *)malloc(sizeof(Room));

        int index = rand() % (sizeof(roomList) / sizeof(roomList[0]));
        strcpy(newNode->name, roomList[index]);

        newNode->level = min + rand() % (max - min + 1);
        newNode->number =  min + rand() % (max - min + 1);
        newNode->resolution =  min + rand() % (max - min + 1);\

        newNode->next = head;

        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;

        

    }


    return head;
}

Room *buildfor4(int n) {

    Room *S = NULL;
    Room *prevTop = NULL;
    Room *prevBot = NULL;

    for (int i = n; i >= 1; i -= 2) {
        char topName[10];
        sprintf(topName, "a_%d", i);
        Room *currTop = createNode(topName, i, i, 100);


        Room *currBot = NULL;
        if (i - 1 >= 1) {
            char botName[10];
            sprintf(botName, "a_%d", i - 1);
            currBot = createNode(botName, i - 1, i - 1, 50);
            currTop->down = currBot; 
        }

        if (S == NULL) {
            S = currTop;
        } else {
            prevTop->next = currTop;
            currTop->prev = prevTop;

            if (prevBot && currBot) {
                prevBot->next = currBot;
                currBot->prev = prevBot;
            }
        }

        prevTop = currTop;
        prevBot = currBot;

    }

    return S;

}

void printLayout(Room *S) {
    Room *currTop = S;
    printf("Верхний ряд (S -> ...): ");
    while (currTop) {
        printf("[%s] ", currTop->name);
        if (currTop->next) printf("<-> ");
        currTop = currTop->next;
    }
    
    printf("\nСвязи вниз:\n");
    currTop = S;
    while (currTop) {
        if (currTop->down) {
            printf("  %s ---down---> %s", currTop->name, currTop->down->name);
            if (currTop->down->next) 
            printf("\n");
        }
        printf("\n");
        currTop = currTop->next;
    }
}


void printInfoCurrent(Room *node) {
    printf("\nинформация о текущем узле:\n");
    printf("название: %s\n", node->name);
    printf("уровень: %d\n", node->level);
    printf("номер: %d\n", node->number);
    printf("разрешение: %d\n", node->resolution);

}

int moveDown(Room **current) {
    if (*current == NULL) {
        return 0;
    } 

    if ((*current)->down != NULL) {
        *current = (*current)->down;
        return 1;
    }

    printf("вы достигли нижнего уровня!\n");
    return 0;
}

int moveLeft(Room **current) {
    if (*current == NULL) {
        return 0;
    }

    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        return 1;
    }

    printf("вы достигли края слева!\n");
    return 0;
}

int moveRight(Room **current) {
    if (*current == NULL) {
        return 0;
    }

    if ((*current)->next != NULL) {
        *current = (*current)->next;
        return 1;
    }

    printf("вы достигли края справа!\n");
    return 0;
}


int main() {

    int n = 8;

    Room *S = buildfor4(n);
    Room *current = S;

    printLayout(S);
    printInfoCurrent(current);

    char input;
    int running = 1;

    while (running)
    {
        printf("введите команду: ");
        scanf(" %c", &input);

        switch (input)
        {
        case 's': case 'S':
            moveDown(&current);
            break;
        case 'a': case 'A':
            moveLeft(&current);
            break;
        case 'd': case 'D':
            moveRight(&current);
            break;
        case 'c': case 'C':
            printf("\nвыход из программы\n");
            running = 0;
            break;
        default:
            printf("неверно введеная команда! (A/S/D) ");
            break;
        }

        if (running && current != NULL) {
            printInfoCurrent(current);
        }
    }
    


}