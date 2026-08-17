#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateRandom(int *a, int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        *(a + i) = rand() % s + 1;
    }
}

void swap(void *a, int i, int j, int sz)
{
    char *temp = malloc(sz);

    char *t1 = (char *)a + i * sz;
    char *t2 = (char *)a + j * sz;

    memcpy(temp, t1, sz);
    memcpy(t1, t2, sz);
    memcpy(t2, temp, sz);

    free(temp);
}

void heapify(void *a, int n, int i, int (*cmp)(void *, void *), int sz)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && cmp((char *)a + left * sz,
                        (char *)a + largest * sz) > 0)
    {
        largest = left;
    }

    if (right < n && cmp((char *)a + right * sz,
                         (char *)a + largest * sz) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a, i, largest, sz);

        heapify(a, n, largest, cmp, sz);
    }
}

void heap_sort(void *a, int n, int (*cmp)(void *, void *), int sz)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i, cmp, sz);
    }

    for (i = n - 1; i > 0; i--)
    {
        swap(a, 0, i, sz);

        heapify(a, i, 0, cmp, sz);
    }
}

void print(int *a, int s)
{
    int i;

    for (i = 0; i < s; i++)
    {
        printf("%d ", *(a + i));
    }

    printf("\n");
}

struct student
{
    int id;
    float cgpa;
    char *name;
};

int intCmparator(void *i, void *j)
{
    int x = *(int *)i;
    int y = *(int *)j;

    if (x == y)
        return 0;

    if (x < y)
        return -1;

    return 1;
}

int floatCmparator(void *i, void *j)
{
    float x = *(float *)i;
    float y = *(float *)j;

    if (x == y)
        return 0;

    if (x < y)
        return -1;

    return 1;
}

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

int cgpaCmp(void *i, void *j)
{
    struct student *x = (struct student *)i;
    struct student *y = (struct student *)j;

    if (x->cgpa == y->cgpa)
        return 0;

    if (x->cgpa < y->cgpa)
        return -1;

    return 1;
}

int main()
{
    int size = 8;
    int a[size];

    generateRandom(a, size);
    print(a, size);

    heap_sort(a, size, intCmparator, sizeof(int));

    print(a, size);


    float f[6] = {1.2, 3.4, .7, .8, .4, .3};

    heap_sort(f, 6, floatCmparator, sizeof(float));

    int i;

    for (i = 0; i < 6; i++)
    {
        printf("%f ", f[i]);
    }

    printf("\n");


    int n = 7;

    struct student *d =
        (struct student *)malloc(sizeof(struct student) * n);

    float cgpa[] = {1.2f, 2.2f, 1.3f, .7f, 5.4f, 2.3f, .9f};

    char *names[] =
        {"ram", "tina", "tom", "sam", "tom", "david", "harry"};

    for (i = 0; i < n; i++)
    {
        struct student *s =
            (struct student *)malloc(sizeof(struct student));

        s->id = rand() % 100;
        s->cgpa = cgpa[i];
        s->name = names[i];

        d[i] = *s;

        free(s);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d:%s:%.2f, ",
               d[i].id,
               d[i].name,
               d[i].cgpa);
    }

    printf("\n");

    heap_sort(d, n, studentIdCmp, sizeof(struct student));

    for (i = 0; i < n; i++)
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