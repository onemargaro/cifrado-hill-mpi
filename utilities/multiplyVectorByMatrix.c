#include<stdio.h>
#include<stdlib.h>

int* multiplyVector(int *vector);

int main() {
	//Example Vector
	int vectorForExample[3] = {2,14,12};
	//Example of function call
	int *newVector = multiplyVector(vectorForExample);
	printf("Vector devuelto = [%d, %d, %d]\n",*newVector,*(newVector+1),*(newVector+2));

	return 0;
}

/**
 * multiply vector by preset matrix
 * @param 	vector 			pointer to vector
 * @return 	resultVector 	pointer to new vector
 */
int* multiplyVector(int *vector) {
	//Def Matrix
	int matrix[3][3] = {1,2,3, 0,4,5, 1,0,6};
	//Reserving memory for new vector
	int *resultVector = (int*) calloc(3, sizeof(int));
	int i,j;
	//Iterating the matrix and multiplying by the vector pointer
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			*(resultVector + i) += matrix[i][j] * (*(vector + j));
		}
	}
	return resultVector;
}