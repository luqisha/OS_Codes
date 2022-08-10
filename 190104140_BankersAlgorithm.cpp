#include <bits/stdc++.h>
using namespace std;

int allocation[100][50], maximum[100][50], need[100][50], available[50];
vector<int> safeSequence;

void calcNeed(int processes, int resources)
{
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool isSafe(int processes, int resources)
{
    bool finish[processes] = {false};
    vector<int> work(available, available + resources);

    int c = 0;
    
    while (c < processes)
    {
        bool safe = false;
        for (int x = 0; x < processes; x++)
        {
            if (!finish[x])
            {
                int i;
                for (i = 0; i < resources; i++)
                {
                    if (need[x][i] > work[i])
                        break;
                }

                if (i == resources)
                {
                    for (int j = 0; j < resources; j++)
                    {
                        work[j] += allocation[x][j];
                    }

                    safeSequence.push_back(x+1);
                    finish[x] = true;
                    safe = true;
                    c++;
                }
            }
        }

        if (!safe)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int P, R;

    cout << "Enter the no. of processes: ";
    cin >> P;
    cout << "Enter the no. of resources: ";
    cin >> R;

    for (int i = 0; i < P; i++)
    {
        cout << "\nProcess " << i + 1 << "::"<< endl;
        for (int j = 0; j < R; j++)
        {
            cout << "Maximum value for resource " << j + 1 << ": ";
            cin >> maximum[i][j];
        }

        cout << endl;
        for (int j = 0; j < R; j++)
        {
            cout << "Allocation for resource " << j + 1 << ": ";
            cin >> allocation[i][j];
        }
    }

    cout << "\nInput Available Matrix: ";
    for (int i = 0; i < R; i++)
    {
        cin >> available[i];
    }

    calcNeed(P, R);
    cout << endl;

    if (isSafe(P, R))
    {
        cout << "System is currently is safe state and < ";
        for (int i : safeSequence)
        {
            cout << "P" << i << " ";
        }
        cout << "> is the safe sequence." << endl;
    }
    else
    {
        cout << "System is not safe." << endl;
    }

    return 0;
}

/*

sample input #1

4 3
3 2 2
1 0 0
6 1 3
5 1 1
3 1 4
2 1 1
4 2 2
0 0 2
9 3 6

sample input #2

5 3

7 5 3
0 1 0
3 2 2
2 0 0
9 0 2
3 0 2
2 2 2
2 1 1
4 3 3
0 0 2
3 3 2

sample input #3

5 3
7 5 3
0 1 0
3 2 2
2 0 0
9 0 2
3 0 2
2 2 2
2 1 1
4 3 3
0 0 2
3 3 2

*/


