#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* head = NULL;

void insert(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void delete(int val) {
    struct Node *temp = head, *prev = NULL;
    if(temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void display() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    printf("Linked List: ");
    display();
    delete(20);
    printf("After Deletion: ");
    display();
    return 0;
}

