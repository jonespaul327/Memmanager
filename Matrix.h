#include "MemHandler.h"

typedef struct __matrix
{
	int num_rows;
	int num_cols;
	double* elements;
} matrix;

matrix* matrix_malloc(int num_rows, int num_cols);
void matrix_free(matrix* mat);
void set_element(matrix* mat, int row, int col, double val);
double get_element(matrix* mat, int row, int col);
matrix* multiply(matrix* left, matrix* right);
void display(matrix* mat);

//left cols has to be the same as right rows for matrix multiplication
matrix* multiply(matrix* left, matrix* right)
{
	int left_rows = left->num_rows;
	int left_cols = left->num_cols;
	int right_rows = right->num_rows;
	int right_cols = right->num_cols;
	matrix* result = matrix_malloc(left_rows, right_cols);
	
	for (int i = 1; i <= left_rows; i++)
	{
		for (int j = 1; j <= right_cols; j++)
		{
			double val = 0;
			for (int k = 1; k <= left_cols; k++)
			{
				double element_left = get_element(left, i, k);
				double element_right = get_element(right, k, j);
				double mul = element_left * element_right;
				val += mul;
			}
			set_element(result, i, j, val);
		}
	}
	
	return result;
}

void display(matrix* mat) {
	int rows = mat->num_rows;
	int cols = mat->num_cols;
	
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			cout << right << setw(10) << get_element(mat, i, j);
		}
		cout << endl;
	}
}

void set_element(matrix* mat, int row, int col, double val) {
	mat*[row*col] = val;
}

double get_element(matrix* mat, int row, int col){ 
	return mat*[row*col];
}

matrix* matrix_malloc(int num_rows, int num_cols) {
	matrix* myMatrix = new matrix;
	
	myMatrix->num_rows = num_rows;
	myMatrix->num_cols = num_cols;
	
	mem_manager_malloc(num_rows*num_cols*sizeof(matrix*));
	return myMatrix;
}

void matrix_free(matrix* mat) {
	


}

