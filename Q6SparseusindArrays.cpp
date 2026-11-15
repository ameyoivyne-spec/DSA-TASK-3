#include <iostream>
using namespace std;

// Maximum non-zero elements the sparse matrix can store
const int MAX = 100;

// Structure to store one non-zero element as a triple
struct Element {
    int row;
    int col;
    int value;
};

// Class to represent a sparse matrix using arrays
class SparseMatrix {
private:
    Element data[MAX];   // Array of triples
    int rows;            // Total rows in original matrix
    int cols;            // Total columns in original matrix
    int count;           // Number of non-zero elements

public:
    // Constructor
    SparseMatrix() {
        rows = 0;
        cols = 0;
        count = 0;
    }

    // Read a 2D matrix and convert it to sparse representation
    void create(int matrix[][10], int r, int c) {
        rows = r;
        cols = c;
        count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    data[count].row   = i;
                    data[count].col   = j;
                    data[count].value = matrix[i][j];
                    count++;
                }
            }
        }
    }

    // Display the sparse representation (triples)
    void displaySparse() {
        cout << "\nSparse Matrix Representation (row, col, value):\n";
        cout << "----------------------\n";
        cout << "| Row | Col | Value |\n";
        cout << "----------------------\n";

        // First row holds dimensions and count: (rows, cols, count)
        cout << "| " << rows << "   | " << cols << "   | " << count << "     |\n";
        cout << "----------------------\n";

        for (int i = 0; i < count; i++) {
            cout << "| " << data[i].row
                 << "   | " << data[i].col
                 << "   | " << data[i].value << "     |\n";
        }
        cout << "----------------------\n";
    }

    // Reconstruct and display the original 2D matrix from the sparse form
    void displayOriginal() {
        int matrix[10][10] = {0};   // All zeros initially

        for (int i = 0; i < count; i++) {
            matrix[data[i].row][data[i].col] = data[i].value;
        }

        cout << "\nReconstructed Original Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int matrix[10][10] = {
        {0, 0, 3, 0},
        {0, 0, 0, 0},
        {5, 0, 0, 7},
        {0, 0, 0, 0}
    };

    int rows = 4, cols = 4;

    cout << "Original Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    SparseMatrix sm;
    sm.create(matrix, rows, cols);   // Convert to sparse form

    sm.displaySparse();              // Show the triples
    sm.displayOriginal();            // Rebuild and show original

    return 0;
}
