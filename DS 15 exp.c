#include <stdio.h>
#define SIZE 10
#define EMPTY -1
int hashTable[SIZE];
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;
}
void insert(int key) {
    int i = key % SIZE;
    while (hashTable[i] != EMPTY)
        i = (i + 1) % SIZE;
    hashTable[i] = key;
    printf("%d inserted at %d\n", key, i);
}
void search(int key) {
    int i = key % SIZE, start = i;
    while (hashTable[i] != EMPTY) {
        if (hashTable[i] == key) {
            printf("%d found at %d\n", key, i);
            return;
        }
        i = (i + 1) % SIZE;
        if (i == start) break;
    }
    printf("%d not found\n", key);
}
void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d: %s\n", i, hashTable[i] == EMPTY ? "EMPTY" : "FILLED");
}
int main() {
    int ch, key;
    init();
    while (1) {
        printf("\n1.Insert 2.Search 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 4) break;
        if (ch == 1) {
            printf("Enter key: ");
            scanf("%d", &key);
            insert(key);
        } else if (ch == 2) {
            printf("Enter key: ");
            scanf("%d", &key);
            search(key);
        } else if (ch == 3) {
            display();
        } else {
            printf("Invalid!\n");
        }
    }
    return 0;
}
