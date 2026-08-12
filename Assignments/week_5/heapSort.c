#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void generateRandom(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = rand() % s + 1;
    }
}

void generateAscending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = i;
    }
}

void generateDescending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = s - i;
    }
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void heapify(int a[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i) {

        swap(a, i, largest);

        heapify(a, n, largest);
    }
}

void Sort(int a[], int n) {

    int i;

    for(i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for(i = n - 1; i > 0; i--) {

        swap(a, 0, i);

        heapify(a, i, 0);
    }
}

void print(int a[] , int s){
    int i;
    for(i = 0; i < s ; i++){
        printf("%d " , a[i]);
    }
    printf("\n");
}

int main(){
    struct timeval te;
    int size = 8000;
    int step = 4000;
    int i;
    for(i = 0; i < 8; i++){
        int a[size];

        // generateRandom(a, size);
        // generateAscending(a, size);
        generateDescending(a, size);
        // print(a, size);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

        Sort(a ,size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

        printf("%lld\n", end - start);

        // print(a, size);

        size += step;
    }

    printf("\n");
    return 0;
}