=======================================================================================================
Time calculation for bubble sort and selection sort.

#include<stdio.h>
#include<time.h>	          //To include clock function (used to calculate time taken by function


void bubble_sort(int A[],int n)	//Function to perform bubble sort
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				temp = A[j+1];
				A[j+1] = A[j];
				A[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++)                //To print sorted array
	{
	    printf("%d",A[i]," , ");
	    printf(" , ");
	}
}

void selection_sort(int A[],int n)	//Function to perform selection sort
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[i])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++)                //To print sorted array
	{
	    printf("%d",A[i]);
	    printf(" , ");
	}
}

int main()
{
	int n,i;
	clock_t st,en;
	double t;
	printf("Enter size of the array: ");	
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)		//Input of array
	{
		printf("\nEnter the %d element of the array: ",i+1);
		scanf("%d",&A[i]);
	}
	int B[n];
	for(i=0;i<n;i++)		//Making 2 copies of entered array – one for bubble sort
	B[i]=A[i];			// and another for selection sort	 
	st = clock();				//starting of clock
	bubble_sort(A,n);			//calling bubble sort function
	en= clock();				//ending of clock 1
	t= (double)(en-st)/CLOCKS_PER_SEC;		//time elapsed for bubble sort
	printf("Time taken for Bubble sort is :%f \n",t);
	st = clock();				//clock for selection sort
	selection_sort(B,n);			//function calling
	en=clock();				//ending of clock 2
	t= (double)(en-st)/CLOCKS_PER_SEC;		//time elapsed for selection sort
	printf("Time taken for Selection sort is :%f \n",t);
	return 0;
}


======================================================================================================