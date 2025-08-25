#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;
void enqueue(int val) {
    if (rear == SIZE - 1) printf("Queue Full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}
void dequeue() {
    if (front == -1 || front > rear) printf("Queue Empty\n");
    else front++;
}
void display() {
    if (front == -1 || front > rear) printf("Queue Empty\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();     // Output: 10 20 30
    dequeue();
    display();     // Output: 20 30
    return 0;
}
