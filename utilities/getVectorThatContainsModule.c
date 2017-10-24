#include<stdio.h>
#include<stdlib.h>

int* getVectorThatContainsTheModule(int *vector);

int main() {
	int exampleVector[3] = {66, 116, 74};
	int *result = getVectorThatContainsTheModule(exampleVector);
	printf("Nuevo Vector con Modulo: [%d, %d, %d]\n", *result, *(result+1), *(result+2));
	return 0;
}

/**
 * get the requested vector module
 * @param 	vector 			pointer to vector
 * @return 	resultVector 	pointer to new vector
 */
int* getVectorThatContainsTheModule(int *vector) {
	int numModule = 26;
	int i;
	int *resultVector = (int*) calloc(3, sizeof(int));

	for(i=0; i<3; i++) {
		*(resultVector+i) = *(vector+i) % numModule;
	}

	return resultVector;
}