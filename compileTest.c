#include<time.h>
#include<stdio.h>
int proc(int a[])
{
int sum = 0;
int i;
for (i = 0; i < 1000000; i++)
{
	sum += a[i];
}
return sum;
}

int main()
{
	int a[1000000];
	int i;
clock_t begin, end;

	begin = clock();
for (i = 0; i < 1000000; ++i)
{
	a[i] = i + 2*i;
}
	int sum = 0;
	sum = proc(a);
	end = clock();

printf("%f", (double)(end - begin)/CLOCKS_PER_SEC);
return 0;
}