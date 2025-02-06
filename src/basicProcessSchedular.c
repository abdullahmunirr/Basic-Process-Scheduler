#include <stdio.h> 

#define MAXPROCESSES 5
#define TIMEQUANTUM 2

struct Process
{
int pid;
int arrival;
int burst;
int remaining;
int state;
};

void rr(struct Process processes[], int n)
{
printf("Round robin scheduling (Time = %d)\n", TIMEQUANTUM);

int time = 0; 
int done;

do
{
done = 1;


for(int i = 0; i<n; i++)
{
if(processes[i].remaining > 0)
{
done = 0;
}
printf("Time %d: Process %d is Running\n", time, processes[i].pid);


if (processes[i].remaining > TIMEQUANTUM)
{
time += TIMEQUANTUM;
processes[i].remaining -= TIMEQUANTUM;
}
else
{
time += processes[i].remaining;
processes[i].remaining = 0;
printf("Time %d: Process %d is Terminated\n", time, processes[i].pid);
}
}
} while (!done);
}

void fcfs(struct Process processes[], int n)
{
printf("Round robin scheduling (Time = %d)\n", TIMEQUANTUM);

int time = 0;
for(int i = 0; i<n; i++)
{
printf("Time %d: Process %d is Running\n", time, processes[i].pid);
time += processes[i].burst;

printf("Time %d: Process %d is Terminated\n", time, processes[i].pid);
}
}

int main ()
{
struct Process processes[MAXPROCESSES] = {{1, 0, 5, 5, 0}, {2, 1, 3, 3, 0}, {3, 2, 8, 8, 0}, {4, 3, 6, 6, 0}, {5, 4, 2, 2, 0}};

int choice; 

printf("Choose Scheduling Algorithm:\n1. First Come First Serve (FCFS)\n2. Round Robin (RR)\n");
scanf("%d", &choice);

if(choice == 1)
{
rr(processes,MAXPROCESSES);
}
else if(choice == 2)
{
fcfs(processes, MAXPROCESSES);
}
else
{
printf("Invalid choice!\n");
}

return 0;
}
