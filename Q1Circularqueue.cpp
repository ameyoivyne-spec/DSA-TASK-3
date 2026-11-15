#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;       // Dynamically allocated array for queue elements
    int capacity;     // Maximum number of elements
    int front;        // Index of front element
    int rear;         // Index of rear element

public:
    // Constructor
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Insert element at rear
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        cout << "Enqueued: " << item << "\n";
    }

    // Remove element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        int item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        cout << "Dequeued: " << item << "\n";
        return item;
    }

    // Display queue contents
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();

    return 0;
}
