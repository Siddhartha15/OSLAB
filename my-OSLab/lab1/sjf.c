
#include<stdio.h>

typedef struct fcfs
{	int vis;
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}node;

int main()
{
	float n;int i,j,max=0,min;
	node a[10],t;
	printf("enter the total no of processors:\n");
	scanf("%f",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter the arrival time and burst time of processor %d:",i);
		a[i].pid=i;
		scanf("%d",&a[i].at);
		scanf("%d",&a[i].bt);
		if(a[i].bt>max)
			max=a[i].bt;
		a[i].vis=0;
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
	int in;
	int k=a[0].at;
	if(a[0].at!=0)
	{
		printf("\nProcessor is idle from time t=0 ms to t=%d ms\n",a[0].at);
	}
	for(i=0;i<n;i++)
	{	if(a[i].at>k)
		{
			printf("\nprocessor is idle from t=%d to %d\n",k,a[i].at);
			k=a[i].at;
		}
		min=max;
		for(j=0;a[j].at<=k;j++)
		{
			if(a[j].bt<min && a[j].vis==0)
			{
				min=a[j].bt;
				in=j;
			}
		}
		if(in==-1)
		{
			for(j=0;j<n;j++)
			{
				if(a[j].vis==0)
				{
					in=j;
					break;
				}
			}
		}
		a[in].vis=1;
		a[in].ct=k+a[in].bt;
		a[in].tat=a[in].ct-a[in].at;
		a[in].wt=a[in].tat-a[in].bt;
		k=k+a[in].bt;
		in=-1;
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
