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

} Room;


Room *createNode(char name[], int level, int number, int resolution) {

    Room *newRoom = (Room *)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->level = level;
    newRoom->number = number;
    newRoom->resolution = resolution;

    newRoom->next = NULL;

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
        head = newNode;
        

    }


    return head;
}


int main() {

    Room *head = createNode("headROOM", 4, 2, 1);

    head = ListsFilling(head, 4);
    printlist(head);

}