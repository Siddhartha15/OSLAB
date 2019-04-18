#include<stdio.h>

typedef struct fcfs
{	int visited;
	int pid;
	int at;
	int bt;
	int prio;
	int ct;
	int tat;
	int wt;
}node;

int main()
{
	float n;int i,j,prio,id,small;
	node a[10],t;
	printf("enter the total no of processors:\n");
	scanf("%f",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter the arrival time,burst time and priority of processor %d:",i);
		a[i].pid=i;
		scanf("%d",&a[i].at);
		scanf("%d",&a[i].bt);
		scanf("%d",&a[i].prio);
		a[i].visited=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].at>a[j].at)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int time=0;
	int flag=1;
	while(flag)
	{	j=0;
		id=-1;
		small=1000;
		while(time>=a[j].at)
		{
			if(a[j].prio<small &&a[j].visited==0)
			{
				
				small=a[j].prio;
				id=j;
			}
			j++;
		}
		if(id==-1)
		{
			for(j=0;j<n;j++)
			{
				if(a[j].at>time)
				{
					id=j;
					small=a[j].prio;
					break;
				}
			}
		}
		if(a[id].at > time)
		{
			printf("The process was idle from %d to %d\n",time,a[id].at );
			time  = a[id].at;
			
		}						
		else
		{
			a[id].visited=1;
			a[id].ct=time+a[id].bt;
			a[id].tat=a[id].ct-a[id].at;
			a[id].wt=a[id].tat-a[id].bt;
			time=time+a[id].bt;
		}
		int count=0,k;
		for (k = 0; k < n; ++k)
			if ( a[k].visited == 1)	
				count++;
		if (count == n)
			flag = 0;


	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].pid>a[j].pid)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	float s1=0,s2=0;
	printf("P.I.D.--A.T.--B.T.--C.T.--T.A.T.--W.T.\n");
	for(i=0;i<n;i++)
	{
		printf("%4d%6d%6d%6d%8d%6d\n",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
		s1=s1+a[i].tat;
		s2=s2+a[i].wt;		
	}
	printf("Average waiting time=%f\n",(float)s2/n);
	printf("Average turn around time=%f",(float)s1/n);

}			
