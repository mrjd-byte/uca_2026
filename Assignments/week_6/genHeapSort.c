#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(void *a, int i, int j, int sz)
{
    char temp[sz];

    char *t1 = (char *)a + i * sz;
    char *t2 = (char *)a + j * sz;

    memcpy(temp, t1, sz);
    memcpy(t1, t2, sz);
    memcpy(t2, temp, sz);
}




void heapify(void *a, int n, int i,
             int (*cmp)(void *, void *), int sz)
{
    while (1)
    {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

    
        if (left < n &&
            cmp((char *)a + left * sz,
                (char *)a + largest * sz) > 0)
        {
            largest = left;
        }

      
        if (right < n &&
            cmp((char *)a + right * sz,
                (char *)a + largest * sz) > 0)
        {
            largest = right;
        }

        if (largest == i)
            break;

        swap(a, i, largest, sz);

        i = largest;
    }
}



void heap_sort(void *a, int n,
               int (*cmp)(void *, void *), int sz)
{
    

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i, cmp, sz);
    }


    for (int i = n - 1; i > 0; i--)
    {
    
        swap(a, 0, i, sz);

        heapify(a, i, 0, cmp, sz);
    }
}



int intComparator(void *i, void *j)
{
    int x = *(int *)i;
    int y = *(int *)j;

    if (x == y)
        return 0;

    if (x < y)
        return -1;

    return 1;
}



int floatComparator(void *i, void *j)
{
    float x = *(float *)i;
    float y = *(float *)j;

    if (x == y)
        return 0;

    if (x < y)
        return -1;

    return 1;
}



struct student
{
    int id;
    float cgpa;
    char *name;
};



int studentIdCmp(void *i, void *j)
{
    struct student *x = (struct student *)i;
    struct student *y = (struct student *)j;

    if (x->id == y->id)
        return 0;

    if (x->id < y->id)
        return -1;

    return 1;
}



int main()
{

    int size = 8;
    int a[size] = {7, 2, 8, 1, 5, 3, 6, 4};

    printf("Before sorting:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    heap_sort(a, size, intComparator, sizeof(int));

    printf("After sorting:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\n");



    float f[6] = {1.2, 3.4, .7, .8, .4, .3};

    heap_sort(f, 6, floatComparator, sizeof(float));

    printf("Floats:\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%f ", f[i]);
    }

    printf("\n\n");



    int n = 7;

    struct student *d =
        (struct student *)malloc(sizeof(struct student) * n);

    float cgpa[] =
        {1.2f, 2.2f, 1.3f, .7f, 5.4f, 2.3f, .9f};

    char *names[] =
        {"ram", "tina", "tom", "sam", "tom", "david", "harry"};

    for (int i = 0; i < n; i++)
    {
        d[i].id = rand() % 100;
        d[i].cgpa = cgpa[i];
        d[i].name = names[i];
    }

    printf("Students before sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d:%s:%.2f, ",
               d[i].id,
               d[i].name,
               d[i].cgpa);
    }

    printf("\n");

    heap_sort(d, n, studentIdCmp, sizeof(struct student));

    printf("Students after sorting by ID:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d:%s:%.2f, ",
               d[i].id,
               d[i].name,
               d[i].cgpa);
    }

    printf("\n");

    free(d);

    return 0;
}