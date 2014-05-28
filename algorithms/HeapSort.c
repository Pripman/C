#include <stdio.h>
#include <time.h>

#define ARRL(x)(sizeof(x)/ sizeof(x[0]))

int Left(int i)
{	
		return((i * 2) + 1);
}

int Right(int i)
{
		return((i * 2) + 2);
}

void Swap (int *a, int *b)
{
	int temp = 0;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
	
void MaxHeapify(int A[], int i, int HeapSize)
{
	int left = Left(i);
	int right = Right(i);
	int Largest = 0;
	
	if((left <= HeapSize) && A[i] < A[left])
		Largest = left;
		
	else Largest = i;
	
	if((right <= HeapSize) && A[Largest] < A[right])
		Largest = right;
	
	if(i != Largest)
	{		
		Swap(&A[i], &A[Largest]);
		MaxHeapify(A, Largest, HeapSize);
	}
}

void BuildMaxHeap(int A[], int length)
{
	int j = (length);
	int i = 0;	
	for(i = ((j-1)/2); i >= 0; i--)
	{
			MaxHeapify(A, i, j);
	}
}

void HeapSort(int A[], int length)
{
	int i = 0;
	
	BuildMaxHeap(A, length);
	for(i = length; i > 0; i--)
	{		
		Swap(&A[i], &A[0]);
		MaxHeapify(A, 0, i -1);	
	}
}

int main(void)
{
	int A[] = {2, 6, 4, 5, 3, 7, 1};
	int i = 0;
	clock_t begin, end;
	
	printf("Tal før sortering:\n  ");
	
	for(i = 0; i < ARRL(A); i++)
		printf("%d  ", A[i]);
		
	printf("\n");
	
	begin = clock();
	HeapSort(A, ARRL(A)-1);
	end = clock();
	
	printf("Tal efter sortering:\n  ");
	
	for(i = 0; i < ARRL(A); i++)
		printf("%d  ", A[i]);
		
	printf("\n");	
	
	printf("Kørselstid = %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
}