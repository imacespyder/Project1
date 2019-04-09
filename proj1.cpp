#include<stdio.h>
int main()
{
	int i, types[20],n;
	int rtime[20];
	printf("Number of  total process: ");
	scanf("%d",&n);
	printf("Enter data\n");
	for(i=0;i<n;i++)
	{
		printf("Response time of P%d (in milliseconds): ",i);
		scanf("%d",&rtime[i]);
		if(rtime[i]==1)
		{
			types[i]=1;
		}
		else
		{
			types[i]=0;
		}
	}
	printf("Process No.\tResponse Time\tType\t\tPriority");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t\t\t%dms\t\t\t",i,rtime[i]);
		if(types[i]==1)
		{
			printf("Process is Interactive\tHigh");
		}
		else
		{
			printf("process is Non-Interactive\tLow");
		}
	}
}
