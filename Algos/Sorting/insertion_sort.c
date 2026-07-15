#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 8
#define START_SIZE 8000
#define STEP_SIZE 4000
double currentTimeMillis(){
	return (double)clock()*1000.0 / CLOCKS_PER_SEC;
}
void generateRandom(int arr[], int size){
	for(int i = 0;i<size;i++){
		arr[i] = rand() % 100000;
	}
}
void generateAscending(int arr[], int size){
	for(int i = 0;i<size;i++){
		arr[i] = i;
	}
}
void generateDescending(int arr[], int size){
	for(int i = 0;i<size;i++){
		arr[i] = size - i;
	}
}
void insertionSort(int arr[], int n){
	for(int i = 1;i<n;i++){
		int key = arr[i];
		int j = i-1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
void benchmarkRandom(){
	printf("\n============== Random Input ==============\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateRandom(arr,size);
		double start = currentTimeMillis();
		insertionSort(arr,size);
		double end = currentTimeMillis();
		printf("%-10d %-15.3f\n",size,end-start);
		free(arr);
	}
}
void benchmarkAscending(){
	printf("\n================ Ascending Input ==========\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateAscending(arr,size);
		double start = currentTimeMillis();
		insertionSort(arr,size);
		double end = currentTimeMillis();
		printf("%-10d %-15.3f\n",size,end-start);
		free(arr);
	}
}
void benchmarkDescending(){
	printf("\n============== Descending Input =============\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateDescending(arr,size);
		double start = currentTimeMillis();
		insertionSort(arr,size);
		double end = currentTimeMillis();
		printf("%-10d %-15.3f\n", size, end - start);
		free(arr);
	}
}
int main(){
	srand(time(NULL));
	benchmarkRandom();
	benchmarkAscending();
	benchmarkDescending();
	return 0;
}

