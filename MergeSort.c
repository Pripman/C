#include <stdio.h>
#include <limits.h>
#include <time.h>
#define ARRLEN(x) (sizeof(x)/sizeof(x[0]))


void MergeSort(int [], int, int);
void Merge(int [], int, int, int);

int main(void)
{
	int A[] = {6, 2, 4, 3, 5, 1}; 
	int i = 0;

	
	clock_t begin, end;
	
	printf("Tal før sortering:\n  ");
	
	for(i = 0; i < ARRLEN(A); i++)
		printf("%d  ", A[i]);
		
	printf("\n");
	
	begin = clock();
	MergeSort(A, 0, ARRLEN(A) - 1);
	end = clock();
	
	printf("Tal efter sortering:\n  ");
	
	for(i = 0; i < ARRLEN(A); i++)	
		printf("%d  ", A[i]);
		
	printf("\n");	
	
	printf("Kørselstid = %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

void MergeSort(int A[], int p, int r)
{
	if(p < r)
	{
		int q = ((p + r)/2);
		
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

void Merge(int *A, int p, int q, int r)
{
	int L[q - p + 1];
	int R[r - q];
	int i = 0;
	int j = 0;
	int k = 0;
	
	for(k = p; k <=  q; k++)
	{
		L[i] = A[k];
		i++;
	}
	
	for(k = q + 1 ; k <= r; k++)
	{
		R[j] = A[k];		
		j++;
	}	
	
	i = 0;
	j = 0;
	L[q - p + 1] = INT_MAX;
	R[r - q] = INT_MAX;

	for(k = p; k <= r; k++)
	{
		if(L[i] > R[j])
		{
			
			A[k] = R[j];
			j++;
			
		}
		else
		{
			
			A[k] = L[i];
			i++;
			
		}
	}
}
