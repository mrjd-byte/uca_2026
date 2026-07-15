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
void heapify(int arr[], int n ,int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n,largest);
	}
}
void heapSort(int arr[], int n){
	for(int i = n/2 - 1;i >= 0 ;i--){
		heapify(arr,n,i);
	}
	for(int i = n - 1;i > 0;i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr,i,0);
	}
}
void benchmarkRandom(){
	printf("\n============== Random Input ==============\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateRandom(arr,size);
		double start = currentTimeMillis();
		heapSort(arr,size);
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
		heapSort(arr,size);
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
		heapSort(arr,size);
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

