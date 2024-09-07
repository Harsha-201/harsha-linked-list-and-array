#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int row; // Row index of the non-zero element
    int col; // Column index of the non-zero element
    int value; // Value of the non-zero element
    Node* next; // Pointer to the next node
};

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = new Node();
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

// Recursive function to insert nodes into the linked list
Node* insertNode(Node* head, int row, int col, int value) {
    // Base case: If the head is null, create a new node and return it
    if (head == nullptr) {
        return createNode(row, col, value);
    }

    // Recursive case: Insert the node at the end of the list
    head->next = insertNode(head->next, row, col, value);
    return head;
}

// Recursive function to traverse and display the linked list
void displayLinkedList(Node* head) {
    // Base case: If the head is null, we have reached the end of the list
    if (head == nullptr) {
        return;
    }

    // Display the current node details
    cout << "Row: " << head->row << ", Column: " << head->col 
         << ", Value: " << head->value << ", Next Node Address: " << head->next << endl;

    // Recursive call to display the next node
    displayLinkedList(head->next);
}

// Function to manually insert values from the user
void manualInsert(Node*& head, int rows, int cols) {
    cout << "Enter the elements for the sparse matrix (non-zero values only):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> value;
            if (value != 0) {
                head = insertNode(head, i, j, value); // Insert the non-zero element into the linked list
            }
        }
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    Node* head = nullptr; // Initialize the linked list head to null

    // Insert values manually
    manualInsert(head, rows, cols);

    // Display the linked list
    cout << "\nSparse Matrix Linked List Representation:\n";
    displayLinkedList(head);

    return 0;
}



