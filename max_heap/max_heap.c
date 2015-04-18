#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

typedef struct max_heap_s max_heap_t;

typedef int (*mh_getmax_pt) (max_heap_t *mh);
typedef void (*mh_insert_pt) (max_heap_t *mh, int d);
typedef int (*mh_extract_max_pt) (max_heap_t *mh);
typedef void (*mh_sort_pt) (max_heap_t *mh);
typedef void (*mh_maxheap_pt) (max_heap_t *mh);

struct max_heap_s
{
    int *data;
    int len;
    int size;
    mh_getmax_pt getmax;
    mh_insert_pt insert;
    mh_extract_max_pt extract_max;
    mh_maxheap_pt maxheap;
    mh_sort_pt sort;
};

#define PARENT(i)  (i/2)
#define LEFT(i)    (i*2)
#define RIGHT(i)    (i*2+1)

int mh_getmax(max_heap_t *mh)
{
    return mh->data[0];
}

static void maxheapify(int data[], int i, int len)
{
    int l = LEFT(i);
    int r = RIGHT(i);

    /*
    int k;
    for(k=0;k<len;++k)
    {
        printf("%d ",data[k]);
    }
    printf("\n");
    printf("i=%d l=%d r=%d\n", i, l, r);
    */
    int large = 0;
    if((l < len) && (data[l] > data[i]))
    {
        large = l;
    }
    else
    {
        large = i;
    }

    if((r < len) && (data[r] > data[large]))
    {
        large = r;
    }

    if(large!=i)
    {
        int tmp = data[large];
        data[large] = data[i];
        data[i] = tmp;
        maxheapify(data, large, len);
    }
}

static void increase_key(int data[], int i, int key)
{
    if(key < data[i])
    {
        printf("increased key is less than current key\n");
        return;
    }

    data[i] = key;
    int tmp;
    int p = PARENT(i);
    while((i >0) && (data[p] < data[i]))
    {
        tmp =  data[p];
        data[p] = data[i];
        data[i] = tmp;
        i=p;
        p=PARENT(i);
    }
}

void mh_insert(max_heap_t *mh, int d)
{
    if(mh->len >= mh->size)
    {
        printf("data overflow\n");
        return;
    }

    mh->data[mh->len] = INT_MIN;
    increase_key(mh->data, mh->len, d);
    mh->len += 1;
}

int mh_extract_max(max_heap_t *mh)
{
    if(mh->len < 1)
    {
        return -1;
    }
    int max = mh->data[0];
    mh->data[0] = mh->data[mh->len-1];
    mh->len -= 1;
    maxheapify(mh->data, 0, mh->len);
    return max;
}

void mh_sort(max_heap_t *mh)
{
    int i;
    int tmp;
    for(i=mh->len-1;i>0;--i)
    {
        tmp = mh->data[i];
        mh->data[i] = mh->data[0];
        mh->data[0] = tmp;
        maxheapify(mh->data, 0, i);
    }
}

void mh_maxheap(max_heap_t *mh)
{
    int i;
    for(i = mh->len/2 - 1; i >= 0; --i)
    {
        maxheapify(mh->data, i, mh->len);
    }
}

#define init_max_heap_t(mh); \
        mh->getmax = mh_getmax; \
        mh->insert = mh_insert; \
        mh->extract_max = mh_extract_max; \
        mh->sort = mh_sort; \
        mh->maxheap = mh_maxheap;

max_heap_t * create_max_heap(int data[], int len, int size)
{
    max_heap_t *mh = malloc(sizeof(max_heap_t));
    mh->data = malloc(size);
    mh->len = len;
    mh->size = size;
    init_max_heap_t(mh);
    memcpy(mh->data, data, len*4);
    int i = 0;
    for(i = len/2 - 1; i >= 0; --i)
    {
        maxheapify(mh->data, i, len);
    }
    return mh;
}

void dump_max_heap(max_heap_t *mh)
{
    printf("len=%d\n", mh->len);
    printf("size=%d\n", mh->size);
    int i = 0;
    for(i=0;i<mh->len;++i)
    {
        printf("%d ", mh->data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a[] = {8,9,9,10,2,6,4,3,1,10};
    int len = sizeof(a)/sizeof(int);
    max_heap_t *mh = create_max_heap(a, len, 256);
    dump_max_heap(mh);
    printf("max=%d\n", mh->getmax(mh));
    mh->sort(mh);
    dump_max_heap(mh);
    mh->maxheap(mh);
    dump_max_heap(mh);
    printf("extract_max=%d\n", mh->extract_max(mh));
    printf("extract_max=%d\n", mh->extract_max(mh));
    dump_max_heap(mh);
    mh->insert(mh, 11);
    dump_max_heap(mh);
    mh->sort(mh);
    dump_max_heap(mh);
    return 0;
}
