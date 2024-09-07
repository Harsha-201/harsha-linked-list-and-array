#include <iostream>
#include <vector>

using namespace std;

// Structure to hold a non-zero element with its row, column and value
struct Element {
    int row;
    int col;
    int value;
};

void inputSparseMatrix(int rows, int cols, vector<Element>& elements) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            cout << "Enter element at position (" << i << "," << j << "): ";
            cin >> value;
            if (value != 0) {
                // Only store non-zero values
                elements.push_back({i, j, value});
            }
        }
    }
}

// Function to display the simple sparse matrix representation
void displaySparseMatrix(const vector<Element>& elements) {
    cout << "\nSparse Matrix Representation (Row, Column, Value):\n";
    for (const auto& elem : elements) {
        cout << "(" << elem.row << ", " << elem.col << ", " << elem.value << ")\n";
    }
}

int main() {
    int rows, cols;

    // Input number of rows and columns
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Vector to store the sparse matrix elements (row, column, value)
    vector<Element> elements;

    // Input matrix elements
    inputSparseMatrix(rows, cols, elements);

    // Display the sparse matrix representation
    displaySparseMatrix(elements);

    return 0;
}


