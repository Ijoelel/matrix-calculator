#include <iostream>
using namespace std;

int main(){

	int x;
	cin >> x;
	float matrix[x][x];
	int step = 1 + (x-2) * 2 + (x-2) * (x-3) / 2;
	
	for(int i = 0; i < x;i++){
		for(int j = 0; j < x; j++){
			cin >> matrix[i][j];
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

	cout << endl << result;

	return 0;
}