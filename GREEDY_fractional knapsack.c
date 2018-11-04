===============================================================================================
/*TIME COMPLEXITY
FRACTIONAL KNAPSACK PROBLEM*/


# include<stdio.h>
# include<time.h>
 
void knapsack(int n, float weight[], float profit[], float capacity) 	//function definition 
{
   	float net[20], tp = 0;
   	int i, j, k;
   	k = capacity;	
   	for (i = 0; i < n; i++)
      	net[i] = 0.0;
 	for (i = 0; i < n; i++) 
	{
      		if (weight[i] > k)			//To select the fractional weight
         		break;
      		else 
		{
         			net[i] = 1.0;
         			tp = tp + profit[i];
         			k = k - weight[i];
      		}
   	}
 	if (i < n)
      	net[i] = k / weight[i];
 	tp = tp + (net[i] * profit[i]);				//to calculate the net profit
 	printf("\nThe result Profit is:- ");
   	for (i = 0; i < n; i++)
      	printf("%f ,", net[i]);
 	printf("\nMaximum profit is:- %f", tp);
 }
 
int main() 
{
   	float weight[20], profit[20],capacity;
   	int num, i, j,item[22];
   	float ratio[20], temp;
	clock_t s,end;
	float t;
 	printf("\nEnter the no. of objects:- ");
   	scanf("%d", &num);
   	for (i = 0; i <num; i++) 
	{
      		printf("Enter item : ");
      		scanf("%d", &item[i]);
      		printf("Enter weight : ");
      		scanf("%f", &weight[i]);
      		printf("Enter profit : ");
      		scanf("%f", &profit[i]);
   	}
 	printf("\nEnter the capacity of kanpsack:- ");
   	scanf("%f", &capacity);
 	for (i = 0; i < num; i++) 
	{
      		ratio[i] = profit[i] / weight[i];
   	}
 	for (i = 0; i < num; i++) 
	{
      		for (j = i + 1; j < num; j++) 
		{
         			if (ratio[i] < ratio[j]) 		//swapping the items acc to ratio
			{					//to get maximum profit
            			temp = ratio[j];
            			ratio[j] = ratio[i];
            			ratio[i] = temp;
 				temp = weight[j];
            			weight[j] = weight[i];
            			weight[i] = temp;
 				temp = profit[j];
            			profit[j] = profit[i];
            			profit[i] = temp;
            			temp = item[j];
            			item[j] = item[i];
            			item[i] = temp;
         			}
      		}
   	}
    	printf("Sorted by profit to weight ratio\n");
   	for (i=0;i<num;i++)
   	{
   
   	    printf("Item \t     Profit \t       Weight \t       Ratio \t\n");	//to print the items
   	    printf("%d \t    %f \t   %f \t    %f \n",item[i],profit[i],weight[i],ratio[i]);
   	}
	s=clock();							//start of clock time
	knapsack(num, weight, profit, capacity);			//function calling
	end=clock();							//end of clock time
	t=(float)(end-s)/CLOCKS_PER_SEC;	//calculation of the time elapsed 
	printf("\nTime taken for processing is: %f\n",t);
   	return(0);
}
========================================================================================================