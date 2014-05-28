#include <stdio.h>
#include<time.h>
#define ARRLEN(x) (sizeof(x)/sizeof(x[0]))

void InsertSort(int *in, int len);
void Print(int *in, int len);

int main(void)
{
	int A[] = {3,5,7,8,6,4,9,2,1};
	int i = 0;
	clock_t begin, end;
		
	printf("Tal før sortering:\n  ");
	
	for(i = 0; i < ARRLEN(A); i++)
		printf("%d  ", A[i]);
		
	printf("\n");
	
	begin = clock();
	InsertSort(A, ARRLEN(A));
	end = clock();
	
	printf("Tal efter sortering:\n  ");
	for(i = 0; i < ARRLEN(A); i++)
		printf("%d  ", A[i]);
		
	printf("\n");	
	printf("Kørselstid = %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

void InsertSort(int *in, int len)
{
    int i = 1;
    int key = 0;
    int j = 0;

    for(i; i < len;i++ )
    {
        key = in[i];
        j = i - 1;

        while(j >= 0 && key < in[j])
        {
            in[j+1]	 = in[j];
            j = j - 1;
		}
        in[j +1 ] = key;
	}
}

