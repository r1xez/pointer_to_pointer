#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
T** create2DArray(int row, int col) {
    T** matrix = new T * [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new T[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 20;
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
T** addRowToArray(T** matrix, int& rows, int cols, int pos) {
    if (pos < 0 || pos > rows) {
        cout << "Invalid position!" << endl;
        return matrix;
    }

    T** newMatrix = new T * [rows + 1];
    for (int i = 0; i < pos; i++) {
        newMatrix[i] = matrix[i];
    }

    newMatrix[pos] = new T[cols];
    for (int j = 0; j < cols; j++) {
        newMatrix[pos][j] = rand() % 20;
    }

    for (int i = pos; i < rows; i++) {
        newMatrix[i + 1] = matrix[i];
    }

    rows++;
    delete[] matrix;
    return newMatrix;
}

template<typename T>
T** deleteRow2DArray(T** matrix, int& rows, int col, int pos) {
    if (pos < 0 || pos >= rows) {
        cout << "Invalid position!" << endl;
        return matrix;
    }

    T** newMatrix = new T * [rows - 1];

    for (int i = 0, newRow = 0; i < rows; i++) {
        if (i != pos) {
            newMatrix[newRow] = new T[col];
            for (int j = 0; j < col; j++) {
                newMatrix[newRow][j] = matrix[i][j];
            }
            newRow++;
        }
    }

    rows--;

    for (int i = 0; i < rows + 1; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return newMatrix;
}

int main() {
    srand(time(0));
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = create2DArray<int>(rows, cols);
    cout << "Original array:" << endl;
    print2DArray(matrix, rows, cols);

    int pos;
    cout << "Enter the position where you want to add a new row: ";
    cin >> pos;

    matrix = addRowToArray(matrix, rows, cols, pos);
    cout << "Array after adding a new row:" << endl;
    print2DArray(matrix, rows, cols);

    cout << "Enter the position of the row you want to delete: ";
    cin >> pos;

    matrix = deleteRow2DArray(matrix, rows, cols, pos);
    cout << "Array after deleting a row:" << endl;
    print2DArray(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
