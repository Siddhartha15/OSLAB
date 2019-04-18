#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct process
{
	int pid;
	int at;
	int bt;
	int ct;
	int wt;
	int tat;
	int rt;
};

int queue[MAX];
int front = 0, rear = 0,i,j;
struct process proc[MAX];

void enqueue(int pid)
{
	queue[rear] = pid;
	rear = (rear+1)%MAX;
}

int dequeue()
{
	if(front == rear)
		return -1;

	int position = queue[front];
	front = (front +1)%MAX;
	return position;
}

int main()
{
	float wt_total = 0.0, tat_total = 0.0, avg_ct = 0.0;
	int n,time_quantum;
	printf("Enter the total processes:\n ");
	scanf("%d", &n);
	for( i=0; i<n; i++)
	{
		printf("Enter the arrival time of the process%d:\n ",i+1);
		scanf("%d", &proc[i].at);
		printf("Enter  burst time of the process%d: \n",i+1);
		scanf("%d", &proc[i].bt);
		proc[i].pid = i+1;
		proc[i].rt = proc[i].bt;
	}
	printf("Enter time quantum:\n ");
	scanf("%d",&time_quantum);

	int time=0; 
	int proc_left=n;   
	int position=-1; 		
	int local_time=0; 
	for( j=0; j<n; j++)
		if(proc[j].at == time)
			enqueue(j);

	while(proc_left)
	{
		if(local_time == 0) 
		{
			if(position != -1)
				enqueue(position);

			position = dequeue();
		}

		for(i=0; i<n; i++)
		{
			if(proc[i].at > time)
				continue;
			if(i==position)
				continue;
			if(proc[i].rt == 0)
				continue;

			proc[i].wt++;
			proc[i].tat++;
		}

		if(position != -1)
		{
			proc[position].rt--;
			proc[position].tat++;
			
			if(proc[position].rt == 0)
			{
				proc_left--;
				local_time = -1;
				position = -1;
			}
		}
		else
			local_time = -1; 

		time++;
		local_time = (local_time +1)%time_quantum;
		for( j=0; j<n; j++)
			if(proc[j].at == time)	
				enqueue(j);
	}

	printf("\n");

	for ( i = 0; i < n; ++i)
	{
		proc[i].ct = proc[i].tat + proc[i].at;
	}

	printf("\nProcess ID | Arrival Time | Burst Time | Completion Time | Waiting time | Turn around time\n");
	for(i=0; i<n; i++)
	{
		printf("%11d|%14d|", proc[i].pid, proc[i].at);
		printf("%12d|%17d|%14d|%17d\n", proc[i].bt,proc[i].ct, proc[i].tat, proc[i].wt);

		tat_total += proc[i].tat;
		wt_total += proc[i].wt;
		avg_ct += proc[i].ct;
	}

	tat_total = tat_total/(1.0*n);
	wt_total = wt_total/(1.0*n);
	avg_ct /= n;
	printf("\nAverage completion time     : %f",avg_ct);
	printf("\nAverage waiting time     : %f",wt_total);
	printf("\nAverage turn around time : %f\n", tat_total);
	
}
