=======================================================================
/*TIME COMPLEXITY 
Insertion sort*/

#include <stdio.h>
#include<time.h>

int main()
{
	int n, array[1000], c, d, t;
	clock_t start,end;
	double time;
 	printf("Enter number of elements : ");
  	scanf("%d", &n);
 	for (c = 1; c <= n; c++)
    	{ 
		printf("Enter the number %d : ", c);
		scanf("%d", &array[c]);
	}
	start=clock();
 	for (c = 1000 ; c <= n - 1; c++) 
	{
    		d = c;
 		while ( d > 0 && array[d-1] > array[d])
 		{
      			t  = array[d];
      			array[d]   = array[d-1];
      			array[d-1] = t;
			d--;
    		}
  	}
	end=clock();
	time = (double)((start-end)/CLOCKS_PER_SEC);
 	printf("Sorted list in ascending order:\n");
	for (c = 0; c <= n - 1; c++) 
	{
		printf("%d , ", array[c]);
  	}
  	printf("Time taken by insertion sort is %f",time);	
 	return 0;
}

==============================================================================