/*
First Come First Serve Algorithm:
--------------------------------
> It is one of the popular scheduling algorithms.
> Processes are dispatched to their arrival time ready queue.

What is Burst Time?
-------------------
Time required for an individual process for its execution in the Central Processing Unit (CPU).

What is Turnaround Time?
------------------------
Turnaround time is the time for which the process spends in the CPU from its arrival to its completion.

What is Waiting Time?
------------------
The difference between turnaround time and burst time of a process.

	[ WAIT_TIME = TURNAROUND_TIME - BURST_TIME ]


[AVERAGE_WAIT_TIME = TOTAL_WAIT_TIMES / NUMBER OF PROCESSES]

[AVERAGE_TURNAROUND_TIME = TOTAL_TURNAROUND_TIMES / NUMBER OF PROCESSES]

Time Complexity:
----------------
O(n) , Every time since this depends upon the variable n, number of processes


*/
#include<iostream.h>
using namespace std;

int main(){
	int i,t,j,n,burst_time[20],wait_time[20], turnaround_time[20],avg_tat=0,avg_wt;
	clrscr();
	cout<<"\nenter the total no of processes";
	cin>>n;
	//reading burst times
	cout<<"\n Enter process burst time";
	for (i=0;i<n;i++) {
		cout<<"\np["<<i+1<<"]";
		cin>>burst_time[i];
	}
	/* Calculating Wait times*/

	wait_time[0] = 0; //Since the first process does not have to wait

	for (i=1;i<n;i++) {
		wait_time[i] = 0;
		for (j=0;j<n;j++)
			wait_time[i] += burst_time[j];
	}

	cout<<"\nProcess\t Burst Time \t Wait Time \t Turnaround Time";
	for(i = 0; i < n;i++){
		turnaround_time[i] = burst_time[i] + wait_time[i];
		avg_wt += wait_time[i];
		avg_tat += turnaround_time[i];
		cout<<"\np["<<i+1<<"]\t\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<turnaround_time[i];
	}
	//calculating averages of wait time and turnaround times
	avg_wt /= n;
	avg_tat /= n;
	cout<<"\n Average waiting time:"<<avg_wt;
	cout<<"\n Average turnaround time:"<<avg_tat;
	getch();
	return 0;
}