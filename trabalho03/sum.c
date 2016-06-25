#include <stdio.h>
#include <stdlib.h>


int* create_array(int array_size) {
	int* array = (int*)malloc(array_size * sizeof(int));
	return array;
}

void read_array(int* array, int array_size) {
	int i;
	for(i = 0; i < array_size; i++) {
		scanf("%d", &array[i]);
	}
}

void show_array(int* array, int array_size) {
	int i;
	for (i = 0; i < array_size; ++i) {
		printf(" %d ", array[i]);
	}
	printf("\n");
}

void max_sum_by_brute_force(int* array, int array_size) {
	int i, j;
	int start = 0, end = -1; 
	int sum, max_sum = 0;

	for(i = 0; i < array_size; i++) {
		sum = 0;
		for(j = i; j < array_size; j++) {
			sum += array[j];
			if(sum > max_sum) {
				max_sum = sum;
				start = i;
				end = j;
			}
		}

	}

	printf("------ Forca Bruta -----\n");
	printf("Maior soma: %d\n", max_sum);
	printf("O inicio é : %d\n", start);
	printf("O fim é : %d\n", end);
}

void max_sum_by_kadane(int* array, int array_size) {
	int i, j;
	int start = 0, end = -1;
	int sum = 0, max_sum = 0;

	for (j = 0; j < array_size; j++) {
		sum += array[j]; 
		if (sum < 0) {
			i = j + 1;
			sum = 0;
		}
		if(sum > max_sum) {
			max_sum = sum;
			start = i;
			end = j;
		}
	}

	printf("----- Kadane -----\n");
	printf("Maior soma: %d\n", max_sum);
	printf("O inicio é : %d\n", start);
	printf("O fim é : %d\n", end);	
}


int main() {

	int array_size;
	scanf("%d", &array_size);

	int* array = create_array(array_size);
	read_array(array, array_size);

	// executa o algoritmo por força bruta
	max_sum_by_brute_force(array, array_size);

	// executa o algoritmo de Kadane
	max_sum_by_kadane(array, array_size);

	return 0;
}

