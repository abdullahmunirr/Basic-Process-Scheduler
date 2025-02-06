#include <iostream>
#include <queue>

using namespace std;

struct Process
{
    int id;
    int burstTime;
    int remainingTime;
    string state;
};

void fcfs(queue<Process> pQueue)
{
    cout << "FCFS Scheduling" << endl;
    while(!pQueue.empty())
    {
        Process p = pQueue.front();
        pQueue.pop();
        
        p.state = "Running";
        cout << "Process " << p.id << " is " << p.state << " (Burst Time: " << p.burstTime << ")" << endl;
        
        p.state = "Terminated";
        cout << "Process " << p.id << " is " << p.state << endl;
    }
}

void rr(queue<Process> pQueue, int timeQuantum)
{
    cout << "Round Robin Scheduling (Time Quantum = " << timeQuantum << ") ---" << endl;
    
    while (!pQueue.empty())
    {
        Process p = pQueue.front();
        pQueue.pop();
        
        if (p.remainingTime > timeQuantum)
        {
            cout << "Process " << p.id << " runs for " << timeQuantum <<
            " units. Remaining: " << p.remainingTime - timeQuantum << endl;
            p.remainingTime -= timeQuantum;
            pQueue.push(p);
        }
        
        else
        {
            cout << "Process " << p.id << " is Running for " << p.remainingTime << " units and is now Terminated" << endl;
        }
    }
}

int main()
{
    queue<Process> processQueue;
    
    processQueue.push({1, 5, 5, "Ready"});
    processQueue.push({2, 3, 3, "Ready"});
    processQueue.push({3, 8, 8, "Ready"});
    
    fcfs(processQueue);
    
    processQueue.push({1, 5, 5, "Ready"});
    processQueue.push({2, 3, 3, "Ready"});
    processQueue.push({3, 8, 8, "Ready"});
    
    rr(processQueue, 2);
    
    return 0;
}
