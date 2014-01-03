#include <stdio.h>

#define ARRL(x)(sizeof(x)/ sizeof(x[0]))

int detect(int A[], int q)
{
	if(A[q] == A[q+1])
		return 1;
	else 
		return 0;
}

int call(int A[], int l, int r)
{
	if(r == l)
	return 0;
	int q = (l + r) / 2;
	int f = detect(A, q);
	int m = call(A, l, q);
	int n = call(A, q + 1, r);
	
	return (m + n + f);
}
	


int main(void)
{
	int A[] = {2, 2 , 4, 5, 5, 6, 6};
	
	int i = call(A, 0, ARRL(A) - 1);
	
	printf("%d \n", i);
	
	
	
}