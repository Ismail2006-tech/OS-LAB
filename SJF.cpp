#include<stdio.h>
void main()
{
	int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float avgwt,avgtat;
	printf("enter number of process:");
	scanf("%d",&n);
	printf("\n enter brust time: \n");
	for(i=0;i<n;i++)
	{
		printf("p%d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++)    
	{
	pos=i;
	for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
			pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
wt[0]=0;
for(i=1;i<n;i++)
	{
		wt[i]=0; 
		for(j=0;j<i;j++)
		wt[i]+=bt[i];
		total+=wt[i];
	}
	avgwt = (float)total/n;
	total=0;
	printf("/nprocess\tbrust time\twaiting time\t turnaround time");
for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("\np%d\t\t%d\t\t%d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	avgtat=(float)total/n;
	printf("/n/naverage waiting time=%f",avgwt);
	printf("/naverage turnaround time=%f/n",avgtat);
	}

