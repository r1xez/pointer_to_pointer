#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** create2DArray(int row, int col) {
    T** matrix = new T * [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new T[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 20 - 10;
        }
    }
    return matrix;
}

template<typename T>
void print2DArray(T** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
T** addColumn2DArray(T** matrix, int row, int col, int pos) {
    T** newMatrix = new T * [row];
    for (int i = 0; i < row; i++) {
        newMatrix[i] = new T[col + 1];
        for (int j = 0; j < col + 1; j++) {
            if (j < pos) {
                newMatrix[i][j] = matrix[i][j];
            }
            else if (j == pos) {
                newMatrix[i][j] = rand() % 20 - 10; 
            }
            else {
                newMatrix[i][j] = matrix[i][j - 1];
            }
        }
    }

    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return newMatrix;
}

template<typename T>
T** deleteColumn2DArray(T** matrix, int row, int col, int pos) {
    T** newMatrix = new T * [row];
    for (int i = 0; i < row; i++) {
        newMatrix[i] = new T[col - 1];
        for (int j = 0; j < col; j++) {
            if (j < pos) {
                newMatrix[i][j] = matrix[i][j];
            }
            else if (j > pos) {
                newMatrix[i][j - 1] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return newMatrix;
}

int main() {
    srand(time(0));
    int row, col, pos;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    int** matrix = create2DArray<int>(row, col);
    cout << "Original array:" << endl;
    print2DArray(matrix, row, col);

    cout << "Enter the position where you want to add a new column: ";
    cin >> pos;

    if (pos < 0 || pos > col) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    matrix = addColumn2DArray(matrix, row, col, pos);
    col++; 
    cout << "Array after adding a new column:" << endl;
    print2DArray(matrix, row, col);

    cout << "Enter the position of the column you want to delete: ";
    cin >> pos;

    if (pos < 0 || pos >= col) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    matrix = deleteColumn2DArray(matrix, row, col, pos);
    col--;  
    cout << "Array after deleting the column:" << endl;
    print2DArray(matrix, row, col);

    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
