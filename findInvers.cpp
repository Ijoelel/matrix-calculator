#include <iostream>
using namespace std;

float determinant(float** matrix_ori, int x){

	float matrix[x][x];
	for (int i = 0; i < x; i++){
		for (int j = 0; j < x; j++){
			matrix[i][j] = matrix_ori[i][j];
		}
	}

	float temp = matrix[0][0];

	// saving the first value of index 0,0 so they can be use to calculate the determinan
	float result = matrix[0][0];

	// change value of matrix[0][0] to 1 with divide all column of row 1 with matrix[0][0]
	for(int i = 0; i < x; i++){
		matrix[0][i] /= temp;
	}

	// using row reduction way's to find determinan
	for(int i = 1; i < x;i++){
		for(int j = 0; j < i; j++){
			if(matrix[i][j] == 0) continue;

			temp =  matrix[i][j] / matrix[j][j];

			for(int k = 0; k < x; k++){
				matrix[i][k] -= matrix[j][k] * temp;
			}
		}
	}

	// multiplicate matrix with index i,i to calculate the determinant
	for(int i = 0; i < x; i++){
		result *= matrix[i][i];
	}

	return result;
}


float** invers(float** matrix_ori, float det, int size){

	// then, find the minor values of the array
	float** matrix = new float*[size];
	for (int i = 0; i < size; ++i){
		matrix[i] = new float[size];
	}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){

			float** minor = new float*[size - 1];
			
			for(int k = 0; k < size - 1; k++){
				minor[k] = new float[size - 1];
			}
			int x = 0;
			int y = 0;

			for(int m = 0; m < size; m++){
				if(m == i) continue;
				for(int n = 0; n < size; n++){
					if(n == j) continue;
					minor[x][y] = matrix_ori[m][n];
					y += 1;
				}
				x += 1;
				y = 0;
			}

			matrix[i][j] = determinant(minor, size-1);
		}
	}
	
	// after that, use cofactor way's
	int count = 1;
	for(int i = 0; i < size; i++){

		if(i % 2 != 0) count = -1;
		else count = 1;

		for(int j = 0; j < size; j++){
			matrix[i][j] *= count;
			count *= -1;
		}

	}
	
	// and find the adjoin of matrix
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(i > 1 or j < 1) continue;
			float sem = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = sem;
		}
	}
	
	// calculate invers with dividing all member of adjoin of matrix with determinant
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			matrix[i][j] /= det;
		}
	}

	return matrix;
}

int main(){

	int x;
	cin >> x;

	// using dynamic array to make an array
	float** matrix = new float*[x];
	for(int i = 0; i < x; i++){
		matrix[i] = new float[x];
	}

	// store value to array
	for(int i = 0; i < x;i++){
		for(int j = 0; j < x;j++){
			cin >> matrix[i][j];
		}
	}

	float det = determinant(matrix, x);

	float** result = invers(matrix, det, x);
	for(int i = 0; i < x;i++){
		for(int j = 0; j < x;j++){
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}