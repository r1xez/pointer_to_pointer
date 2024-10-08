#include <iostream>
#include <ctime>
using namespace std;

void shiftCols(int** arr, int rows, int cols, int colShift) {
   
    colShift = colShift % cols; 
    if (colShift < 0) colShift += cols; 

    for (int j = 0; j < colShift; j++) {
        for (int i = 0; i < rows; i++) {
            int temp = arr[i][0]; 
            for (int k = 0; k < cols - 1; k++) {
                arr[i][k] = arr[i][k + 1]; 
            }
            arr[i][cols - 1] = temp; 
        }
    }
}

void shiftRows(int** arr, int rows, int cols, int rowShift) {
   
    rowShift = rowShift % rows; 
    if (rowShift < 0) rowShift += rows; 

    for (int j = 0; j < rowShift; j++) {
        int* temp = arr[0]; 
        for (int i = 0; i < rows - 1; i++) {
            arr[i] = arr[i + 1]; 
        }
        arr[rows - 1] = temp; 
    }
}

void createArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
}

int main() {
	srand(time(0));
    int rows, cols, rowShift, colShift;

    cout << "Enter number of rows (M): ";
    cin >> rows;
    cout << "Enter number of columns (N): ";
    cin >> cols;

    int** arr = new int* [rows];
    createArray(arr, rows, cols);
    printArray(arr, rows, cols);

    cout << "Enter number of row shifts: ";
    cin >> rowShift;
    shiftRows(arr, rows, cols, rowShift);
    cout << "Matrix after row shift:" << endl;
    printArray(arr, rows, cols);

    cout << "Enter number of column shifts: ";
    cin >> colShift;
    shiftCols(arr, rows, cols, colShift);
    cout << "Matrix after column shift:" << endl;
    printArray(arr, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] arr[i]; 
    }
    delete[] arr;

    return 0;
}