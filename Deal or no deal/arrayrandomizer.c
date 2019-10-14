#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomize ( int arr[], int n )
{
    srand ( time(NULL) );
	int i;
    for ( i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
