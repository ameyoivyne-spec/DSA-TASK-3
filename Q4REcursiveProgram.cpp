#include <iostream>
using namespace std;

// (a) Sum of first N natural numbers
int sumNatural(int n) {
    if (n == 0) return 0;
    return n + sumNatural(n - 1);
}

// (b) Factorial of a number
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// (c) Nth Fibonacci term
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// (d) Generate N Fibonacci terms (recursive helper)
void fibSeries(int n, int arr[], int index) {
    if (index == 0) { arr[0] = 0; fibSeries(n, arr, 1); return; }
    if (index == 1) { arr[1] = 1; fibSeries(n, arr, 2); return; }
    if (index >= n) return;
    arr[index] = arr[index - 1] + arr[index - 2];
    fibSeries(n, arr, index + 1);
}

int main() {
    int choice, n;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Sum of first N natural numbers\n";
        cout << "2. Factorial of a number\n";
        cout << "3. Nth term of Fibonacci\n";
        cout << "4. Generate N terms of Fibonacci\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter N: "; cin >> n;
                cout << "Sum = " << sumNatural(n) << endl;
                break;
            case 2:
                cout << "Enter number: "; cin >> n;
                cout << "Factorial = " << factorial(n) << endl;
                break;
            case 3:
                cout << "Enter N: "; cin >> n;
                cout << "F(" << n << ") = " << fib(n) << endl;
                break;
            case 4: {
                cout << "How many terms? "; cin >> n;
                if (n <= 0) { cout << "Invalid input\n"; break; }
                int* arr = new int[n];
                fibSeries(n, arr, 0);
                cout << "Series: ";
                for (int i = 0; i < n; i++) cout << arr[i] << " ";
                cout << endl;
                delete[] arr;
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}