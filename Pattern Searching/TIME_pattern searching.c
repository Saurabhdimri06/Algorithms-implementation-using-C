========================================================================================
TIME COMPLEXITY
Patter searching in a given text field 

#include<stdio.h>
#include<time.h>

int search(char A[],char B[],int n,int m)	//function to search position of pattern
{						//in the entered text
	int i,j,pos=-1;					
	for(i=0;i<n-m;i++)
	{
		if(A[i]==B[0])
		{
			j=0;
			while(j<m && A[i+j]==B[j])
			j=j+1;
		}
		if(j==m)
		pos=i;
	}
	return pos;
}

int main()
{
	int n,m,pos;
	clock_t start,end;
	double t;
	printf("Enter the respective sizes of Text \n");
	scanf("%d",&n);
	printf("Size of pattern array such that text has more size \n");
	scanf("%d",&m);
	if (n>=m)				//text should be greater than pattern to search 
	{					//for sucessfully
		char TEXT[n],PATTERN[m];
		printf("Enter the text string\n");
		scanf("%s",TEXT);
		printf("Enter the pattern string\n");
		scanf("%s",PATTERN);
		start=clock();					//clock starting
		pos = search(TEXT,PATTERN,n,m);	//function calling
		end=clock();					//clock ending
		t=(double)(start-end)/CLOCKS_PER_SEC;
		printf("The element is found at %d index\n",pos);
		printf("The time taken is %f\n",t);
	}
	else
	{
		printf("The size of pattern cannot be more than text!!");
	}
	return 0;
}

=================================================================================================