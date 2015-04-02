#include <stdio.h>
#include <stdint.h>


void swap(int a[], int i, int j)
{
    if(i==j)
    {
        return;
    }

    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int s, int e)
{
    int pivot = a[e];
    int i,j;

    i=j=s;

    for(j=s;j<e;++j)
    {
        if(a[j]<pivot)
        {
            swap(a, i, j);
            ++i;
        }
    }
    swap(a,i,e);

    return i;
}

void quick_sort(int a[], int s, int e)
{
    if(s>=e)
        return;
    int q = partition(a, s, e);
    //printf("q=%d\n", q);
    quick_sort(a,s, q-1);
    quick_sort(a,q+1,e);
}

void quick_sort_test(int a[], int len)
{
    int i=0;
    
    printf("befor sort:\n");
    for(i=0;i<len;++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    quick_sort(a, 0, len-1);

    printf("after sort:\n");
    for(i=0;i<len;++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    int a[] = {2, 1, 7, 6, 5, 4, 8, 3};

    int len = sizeof(a)/sizeof(int);

    quick_sort_test(a, len);

    int b[] = {};

    len = sizeof(b)/sizeof(int);

    quick_sort_test(b, len);

    int c[] = {9,8,7,6,5,4,3,2,1};

    len = sizeof(c)/sizeof(int);

    quick_sort_test(c, len);

    return 0;
}
