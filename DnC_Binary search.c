================================================================================================
DIVIDE AND CONQUER
Binary Search Time complexity 

#include<stdio.h>
#include<time.h>

int binarysearch(int A[],int n,int el)			//Function to perform binary search
{
	int l,u,mid,flag=0;
	l=0;
	u=n-1;
	while(l<u)
	{
		mid=(l+u)/2;						//finding middle term
		if(el>A[mid])				//dividing problem into smaller problems
		l=mid+1;				//first half array first element to middle 
		else if (el<A[mid])
		u=mid-1;				//second half array first element to middle
		else
		{
			flag=1;
			break;
		}
	}
}

int main()
{
	clock_t start,end;
	double t; int i,n,flag,el;
	printf("Program for Binary Search!\n");
	printf("Enter a sorted array to successfully perform Binary Search. \n");
	printf("Enter the array size you want: ");
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element of the array: ",i+1);
		scanf("%d",&A[i]);
	}
	printf("Enter the element you want to search: ");
	scanf("%d",&el);
	printf("Performing the binary search\n");
	start=clock();							//start clock time
	flag=binarysearch(A,n,el);					//function calling
	end=clock();							//end clock time
	if(flag==1)
	printf("Element does not exist in the array\n");
	else
	printf("Element exist in the array\n");
	t=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken by the process in seconds is : %f\n",t);
	return 0;
}

=================================================================================================