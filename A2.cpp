//=========================== FCFS ============================//
// #include<iostream>
// #include<vector>
// using namespace std;

// struct process{
//     int pid;
//     int arival;
//     int burst;
//     int completion;
//     int turnaround;
//     int waiting;
// };

// void Completion_time(process proc[],int n){
//     proc[0].completion =  proc[0].burst;
//     for(int i=1;i<n;i++){
//         proc[i].completion = proc[i-1].completion + proc[i].burst;
//     }
// };

// void Turnaround_time(process proc[],int n){
//     for(int i=0;i<n;i++){
//         proc[i].turnaround = proc[i].completion - proc[i].arival;
//     }
// };

// void Waiting_time(process proc[],int n)
// {
//     proc[0].waiting = 0;
//     for(int i=1;i<n;i++){
//         proc[i].waiting = proc[i].turnaround - proc[i].burst;
//     }
// };

// void findFCFS(process proc[],int n)
// {
//     Completion_time(proc,n);
//     Turnaround_time(proc,n);
//     Waiting_time(proc,n);
// };

// void printProcesses(process proc[],int n){
//     cout<<"<= FCFS Scheduling =>"<<endl;
//     cout << "PID\tArival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time"<<endl;

//     for(int i=0;i<n;i++)
//     {
//         cout<<proc[i].pid<<"\t\t"<<proc[i].arival<<"\t\t"<<proc[i].burst<<"\t\t"<<proc[i].completion<<"\t\t"<<proc[i].turnaround<<"\t\t"<<proc[i].waiting<<endl;
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter number of procesess : ";
//     cin>>n;

//     process proc[n];
//     for (int i = 0; i < n; ++i) {
//         cout << "Enter details for process " << i + 1 << ":" << endl;
//         cout << "Process ID: ";
//         cin >> proc[i].pid;
//         cout << "Arrival time: ";
//         cin >> proc[i].arival;
//         cout << "Burst time: ";
//         cin >> proc[i].burst;
//     }

//     findFCFS(proc,n);
//     printProcesses(proc,n);

//     return 0;
// }

//=========================== SJF ============================//
#include <iostream>
#include <vector>
using namespace std;

struct process
{
    int pid;
    int arival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

void SJF(process proc[], int n)
{
    int remainingTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = proc[i].burst;
    }

    int currentTime = 0;
    int complete = 0;
    int shortest = 0;
    int minBurst = 9999;

    while (complete < n)
    {
        minBurst = 9999;
        for (int i = 0; i < n; i++)
        {
            if (proc[i].arival <= currentTime && remainingTime[i] < minBurst && remainingTime[i] > 0)
            {
                minBurst = remainingTime[i];
                shortest = i;
            }
        }
        remainingTime[shortest]--;
        if (remainingTime[shortest] == 0)
        {
            complete++;
            proc[shortest].completion = currentTime + 1;
            proc[shortest].turnaround = proc[shortest].completion - proc[shortest].arival;
            proc[shortest].waiting = proc[shortest].turnaround - proc[shortest].burst;
        }
        currentTime++;
    }
};


void printProcesses(process proc[], int n)
{
    cout << "<= SJF Scheduling =>" << endl;
    cout << "PID\tArival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << "\t\t" << proc[i].arival << "\t\t" << proc[i].burst << "\t\t" << proc[i].completion << "\t\t" << proc[i].turnaround << "\t\t" << proc[i].waiting << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of procesess : ";
    cin >> n;

    process proc[n];
    cout << "Enter Process details (ID, Arrival, Burst) !" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter details for process " << i + 1 << ":" << endl;
        cin >> proc[i].pid >> proc[i].arival >> proc[i].burst;
    }

    SJF(proc, n);
    printProcesses(proc, n);

    return 0;
}