
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int *arr;
	int n;
	int i = 0;
	int x = 0;
	int avrg = 0;

	
	printf("insert number\n");

	FILE * fil;

	fil = fopen("testfile.txt", "r");


	arr = (int *)malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++){
		arr[i] = fgetc(fil);
	}	
	fclose(fil);
	for(i = 0; i < n; i++){
		avrg += arr[i];
	}	
	
	avrg = avrg/n;
	printf("average is :%d", avrg);
	
	free(arr);
		
	return 0;
}
