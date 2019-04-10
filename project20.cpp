#include<stdio.h>
int main()
{
	int p[30],bt[30], su[30], wt[30],tat[30],i, k, n, temp;
	float wtavg, tatavg;
	printf("Process in the queue starts from here--- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("This is Burst time process %d --- ", i);
		scanf("%d",&bt[i]);
		printf("This is teacher and student starting  (0/1) ? --- ");
		scanf("%d", &su[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			if(su[i] > su[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=su[i];
				su[i]=su[k];
				su[k]=temp;
			}
		}
	}
	wtavg = wt[0] = 0;
	tatavg = tat[0] = bt[0];
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\n im PROCESS\t im TEACHER/im STUDENT PROCESS \t this is BURST TIME     \tWAITING TIME      \tTURNAROUND TIME");
	
	for(i=0;i<n;i++)
	{
		printf("\n\%d \t\t\t %d \t\t\t\t %d \t\t\t %d \t\t\t%d ",p[i],su[i],bt[i],wt[i],tat[i]);
	}

	printf("\nAverage Waiting Time is --- %f",wtavg/n);
	printf("\nAverage Turnaround Time is --- %f",tatavg/n);

	return 0;
}
