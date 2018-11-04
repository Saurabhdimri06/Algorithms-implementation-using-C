================================================================================================
/*TIME COMPLEXITY
Merge Sort*/ 

#include <stdio.h>
#include <time.h>
 
void mergeSort(int [], int, int, int);			//Merge sort function declaration
void partition(int [],int, int);				//Partition function declaration
 
int main()
{
 	int list[50];
	clock_t start,end;
	double time;
 	int i, size;
    	printf("Enter total number of elements:");
    	scanf("%d", &size);
    	printf("Enter the elements:\n");
    	for(i = 0; i < size; i++)
    	{
         		scanf("%d", &list[i]);
    	}
	start=clock();							//start time of clock	
    	partition(list, 0, size - 1);			//calling of the partation function
	end=clock();							//end time of clock
	time = (double)(start-end)/CLOCKS_PER_SEC;	//calculation of time taken
    	printf("After merge sort:\n");
	printf("Time taken by merge sort is %f",time);
    	for(i = 0;i < size; i++)
    	{
    		printf("%d   ",list[i]);
    	}
 	return 0;
}
 
void partition(int list[],int low,int high)			//Partition function definition
{
    	int mid;
 	if(low < high)
    	{
        		mid = (low + high) / 2;
        		partition(list, low, mid);				//Recurrsive calling
        		partition(list, mid + 1, high);				//Recurrsive calling
        		mergeSort(list, low, mid, high);		//Merge sort function calling 
    	}
}
 
void mergeSort(int list[],int low,int mid,int high)	//Merge sort function definition
{
    	int i, mi, k, lo, temp[50];
    	lo = low;
    	i = low;
    	mi = mid + 1;
    	while ((lo <= mid) && (mi <= high))
    	{
        		if (list[lo] <= list[mi])
        		{
            		temp[i] = list[lo];
            		lo++;
        		}
        		else
        		{
            		temp[i] = list[mi];
            		mi++;
        		}
        		i++;
    	}
    	if (lo > mid)
    	{
        		for (k = mi; k <= high; k++)
        		{
            		temp[i] = list[k];
            		i++;
        		}
    	}
    	else
    	{
        		for (k = lo; k <= mid; k++)
        		{
            		 temp[i] = list[k];
            		 i++;
        		}
    	}
 
    	for (k = low; k <= high; k++)
    	{
        		list[k] = temp[k];
    	}
}

===============================================================================================