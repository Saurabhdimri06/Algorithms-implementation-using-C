=================================================================================================
TIME COMPLEXITY
Binary search and Linear Search

#include<stdio.h>
#include<time.h>

int linearsearch(int A[],int el,int n)				//Funtion to perform linear search
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(A[i]==el)				//Iterating over each element and searching
		{					//for desired element to be searched
			flag=1;
			break;
		}
	}
	return flag;
}
int binarysearch(int A[],int n,int el)				//Function to perform binary search
{
	int l,u,mid,flag=0;
	l=0;
	u=n-1;
	while(l<u)
	{
		mid=(l+u)/2;							//finding middle term
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
	int n,i,el,flag,fg;
	clock_t start,end,st,et;
	double time,t_ime;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element of the array: ",i+1);
		scanf("%d",&A[i]);
	}
	printf("Enter the element you want to search in the array: ");
	scanf("%d",&el);
	start=clock();								//start clock time
	flag=linearsearch(A,el,n);				//function calling inear search
	end=clock();								//end clock time
	time = (double)(start-end)/CLOCKS_PER_SEC;
	st=clock();								//start clock time
	fg=binarysearch(A,n,el);				//function calling Binary search
	et=clock();								//end clock time
	t_ime=(double)(end-start)/CLOCKS_PER_SEC;
	if(flag==1)
	printf("The element exists in the array");
	else
	printf("The element does not exist in the array\n");
	printf("Time taken for linear search is :%f\n",time);
	printf("Time taken by the process in seconds is : %f\n",t_ime);
	return 0;
}

======================================================================================================