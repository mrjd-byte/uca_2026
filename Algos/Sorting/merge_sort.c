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
void merge(int arr[], int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));
	for(int i = 0;i < n1;i++) L[i] = arr[left + i];
	for(int i = 0;i < n2;i++) R[i] = arr[mid + 1 + i];
	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	while(i < n1) arr[k++] = L[i++];
	while(j < n2) arr[k++] = R[j++];
	free(L);
	free(R);
}
void mergeSort(int arr[], int left, int right){
	if(left < right){
		int mid = left + (right - left)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
void benchmarkRandom(){
	printf("\n============== Random Input ==============\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateRandom(arr,size);
		double start = currentTimeMillis();
		mergeSort(arr,0,size-1);
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
		mergeSort(arr,0,size-1);
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
		mergeSort(arr,0,size-1);
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
