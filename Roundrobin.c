=================================================================================================================================
/*TIME COMPLEXITY
TO PREFORM ROUNDROBIN*/

#include<stdio.h> 
#include<time.h> 

int main() 
{ 
  	int count,j,n,time,remain,flag=0,time_quantum; 
  	int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
	clock_t s,end;
	float t;
  	printf("Enter Total Process:\t "); 
  	scanf("%d",&n); 
  	remain=n; 
  	for(count=0;count<n;count++) 
  	{ 
  		printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    		scanf("%d",&at[count]); 
    		scanf("%d",&bt[count]); 
    		rt[count]=bt[count]; 
  	} 
  	printf("Enter Time to be alloted for each job:\t"); 
  	scanf("%d",&time_quantum); 
  	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
	start = clock();								//starting the clock 
  	for(time=0,count=0;remain!=0;) 
  	{ 
    		if(rt[count]<=time_quantum && rt[count]>0) 
    		{ 
      			time+=rt[count]; 
      			rt[count]=0; 
      			flag=1; 
    		} 
    		else if(rt[count]>0) 
    		{ 
      			rt[count]-=time_quantum; 
      			time+=time_quantum; 
    		}	 
    		if(rt[count]==0 && flag==1) 
    		{ 
     			remain--; 
      			printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      			wait_time+=time-at[count]-bt[count]; 
      			turnaround_time+=time-at[count]; 
      			flag=0; 
    		} 
    		if(count==n-1) 
      		count=0; 
    		else if(at[count+1]<=time) 
      			count++; 
    		else 
      			count=0; 
  	} 
	end=clock();								//end of clock time
	t=(float)(end-s)/CLOCKS_PER_SEC;		//time elpased performing the task
  	printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  	printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
	printf(“Avg time take by the algorithm : %f”,t);
  	return 0; 
}

==========================================================================================================