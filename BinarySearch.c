#include <stdio.h>
#include <time.h>



int BinarySearch(int *A, int l, int r, int  NumberToFind)
{
  int q = 0;

  if(l == r)
  {
    if(A[l] == NumberToFind)
      return l;
    else
      return 100;
  }
  q = ((l+r)/2);
  
  if(NumberToFind < A[q])
    return BinarySearch(A, l, q - 1, NumberToFind);
  else return BinarySearch(A, q, r, NumberToFind);

    
}

  
int main(void)
{
  int A[] = {10, 20, 30, 40, 50};

  int NumberToFind = 30;
  int index;
  clock_t begin, end;

  begin = clock();
  index = BinarySearch(A, 0, 4, NumberToFind);
  end = clock();
  printf("index: %d\n", index); 

  printf("Kørselstid = %f\n", (double)(end - begin) / CLOCKS_PER_SEC); 
}

