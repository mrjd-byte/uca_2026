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
int partitionQS(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
	for(int j = low;j < high;j++){
		if(arr[j] < pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return i+1;
}
void quickSort(int arr[], int low, int high){
	if(low < high){
		int pi = partitionQS(arr,low,high);
		quickSort(arr,low,pi - 1);
		quickSort(arr,pi + 1, high);
	}
}
void benchmarkRandom(){
	printf("\n============== Random Input ==============\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateRandom(arr,size);
		double start = currentTimeMillis();
		quickSort(arr,0,size-1);
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
		quickSort(arr,0,size-1);
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
		quickSort(arr,0,size-1);
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
