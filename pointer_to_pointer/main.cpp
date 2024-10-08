#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
void print_2d_array(T** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		cout << "Row " << i << ": ";
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
T** create_2d_array(int rows, int cols)
{
	T** arr = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
		for (size_t j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	return arr;
}


template <typename T>
void delete_2d_array(T** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
template <typename T>
void push_back_2d_array(T**& arr, int& rows, int cols, T* new_row)
{
	T** new_arr = create_2d_array<T>(rows + 1, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			new_arr[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < cols; i++)
	{
		new_arr[rows][i] = new_row[i];
	}
	delete_2d_array(arr, rows);
	arr = new_arr;
	rows++;
}

int main()
{
	srand(time(0));
	int cols, rows;

	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << "Enter the number of columns: ";
	cin >> cols;

	int** arr = create_2d_array<int>(rows, cols);
	print_2d_array(arr, rows, cols);

	cout << "Enter the row to insert: ";
	int* row = new int[cols];
	for (size_t i = 0; i < cols; i++)
	{
		cin >> row[i];
	}

	push_back_2d_array(arr, rows, cols, row);
	print_2d_array(arr, rows, cols);

	delete_2d_array(arr, rows);

	return 0;
}