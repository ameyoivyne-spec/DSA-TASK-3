#include <iostream>
using namespace std;

class Queue {
private:
    int* queue;       // Dynamically allocated array
    int capacity;     // Maximum size of the queue
    int front;        // Index of the front element
    int rear;         // Index of the rear element

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] queue;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == capacity - 1);
    }

    // Enqueue: insert element at the rear
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << item << "\n";
            return;
        }
        if (front == -1) {
            front = 0;          // First element inserted
        }
        rear++;
        queue[rear] = item;
        cout << "Enqueued: " << item << "\n";
    }

    // Dequeue: remove element from the front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue\n";
            return -1;
        }
        int item = queue[front];
        front++;
        cout << "Dequeued: " << item << "\n";
        return item;
    }

    // Display the queue contents
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << "\n";
    }
};

int main() {
    Queue q(5);   // Queue with capacity 5

    // Enqueue operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    // Attempt to enqueue when full (overflow test)
    q.enqueue(60);

    // Dequeue operations
    q.dequeue();
    q.dequeue();
    q.display();

    // Enqueue after dequeue — will overflow because it's a linear queue
    q.enqueue(70);
    q.display();

    // Dequeue remaining elements
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    // Attempt to dequeue from empty queue (underflow test)
    q.dequeue();

    return 0;
}
