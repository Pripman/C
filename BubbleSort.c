#include <stdio.h>

#define ARRL(x)(sizeof(x)/ sizeof(x[0]))

int detect(int l, int r)
{
	if(left == right)
		return 1;
	else 
		return 0;
}

int call(int A[], int l, int r)
{
	int q = (l + r) / 2;
	int f = detect(q, q +1);
	int m = call(A, l, q);
	int n = call(A, q +1, r);
	
	return (m + n + f);
}
	


int main(void)
{
	int A[] = {2, 6, 4, 5, 3, 2};
	
	call(A, 0, ARRLEN(A) - 1);
	
	
	
}