#include <bits/stdc++.h>

using namespace std;

struct process
{
    int pID;
    int aTime;
    int cpuTime;
    int tAroundTime;
    int wTime;

};

bool arrangeForATime (process p1, process p2)
{
    if (p1.aTime == p2.aTime)
    {
        return p1.cpuTime < p2.cpuTime;
    }

    else
    {
        return p1.aTime < p2.aTime;
    }

}

bool arrangeForID (process p1, process p2)
{
    return p1.pID < p2.pID;

}

void calcWaitingTime(process p[], int n)
{
    p[0].wTime = 0;

    for(int i= 1; i< n; i++)
    {
        p[i].wTime = p[i-1].cpuTime + p[i-1].wTime;
    }
}


void calcTurnAroundTime(process p[], int n)
{
    for(int i= 0; i< n; i++)
    {
        p[i].tAroundTime = p[i].cpuTime + p[i].wTime;
    }
}

int main()
{

    cout << "Enter the number of process: ";
    int n;
    cin >> n;

    process p[n];

    cout << "Enter Burst times: ";

    for(int i = 0 ; i< n; i++)
    {
        p[i].pID = i+1;
        cin >> p[i].cpuTime;
    }


    cout << "Enter arrival times: ";

    for(int i = 0 ; i< n; i++)
    {
        cin >> p[i].aTime;
    }

    sort(p, p+n, arrangeForATime);

    calcWaitingTime(p, n);

    calcTurnAroundTime(p, n);

    sort(p, p+n, arrangeForID);

    cout << "PID" << "\t Waiting Time" <<"\t Turnaround Time" << endl;;
    int totalWaitingTime= 0, totalTAroundTime = 0;

    for(int i = 0 ; i< n; i++)
    {
        totalWaitingTime += p[i].wTime;
        totalTAroundTime += p[i].tAroundTime;

        cout << "P" << p[i].pID << ": \t\t" << p[i].wTime << "\t\t" << p[i].tAroundTime << endl;

    }

    cout << "\nAverage Waiting time: " << (float)totalWaitingTime/n << " Average Turnaround time: " << (float)totalTAroundTime/n << endl;;


    return 0;
}

/*
sample_input_1

5
6 2 8 6 4
2 5 1 0 4


sample_input_2

3
5 7 9
4 0 2

*/
