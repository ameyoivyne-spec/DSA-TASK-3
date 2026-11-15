#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

/* a. Insert at front */
void insertFront(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {          /* empty deque */
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;        /* wrap around */
    } else {
        front--;
    }
    deque[front] = item;
    printf("Inserted at front: %d\n", item);
}

/* b. Insert at rear */
void insertRear(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {          /* empty deque */
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;               /* wrap around */
    } else {
        rear++;
    }
    deque[rear] = item;
    printf("Inserted at rear: %d\n", item);
}

/* c. Delete from front */
void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) {        /* single element */
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

/* d. Delete from rear */
void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear) {        /* single element */
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

/* Display deque */
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);
    display();

    deleteFront();
    deleteRear();
    display();

    return 0;
}
