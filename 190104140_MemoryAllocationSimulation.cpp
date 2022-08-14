#include <bits/stdc++.h>

using namespace std;

vector <int> holes, requests;

void bestFit() //doesn't show correct result
{
    int m = holes.size();
    int n = requests.size();

    int out [m][n], x = n;

    for (int i = 0; i < n; i++)
    {
        int fragmentation = INT_MAX, index = -1;
        for (int j = 0; j < m; j++)
        {
            if (holes[j] >= requests [i] && abs(holes[j] - requests [i]) < fragmentation)
            {
                fragmentation = abs (holes[j] - requests [i]);
                index = j;                    
            }
        }

        if (index == -1)
        {
            cout << "External Fragmentation Found";
            x = i;
            break;
        }

        for (int j = 0; j < m; j++)
        {
            if(i == 0)
            {
                out[j][i] = holes [j];
            }
            else
            {
                out[j][i] = out[j][i-1];
            }          
        }

        out[index][i] = fragmentation;    
        
    }

    for (int i = 0; i < n; i++)
    {
        cout << requests[i] << "\t" ;
    }
    cout << endl;

    for (int i = 0; i < m ; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << out[i][j] << "\t" ;
        }
        cout << endl;        
    }
    
}

int main()
{
    
    string input;
    int memSpace;

    cout << "Memory Holes: ";
    getline(cin, input);

    istringstream iss (input);

    while (iss >> memSpace)
    {
        holes.push_back(memSpace);
    }

    cout << "Memory Requests: ";
    getline(cin, input);

    iss.clear();
    iss.str(input);

    while (iss >> memSpace)
    {
        requests.push_back(memSpace);
    }

    bestFit();
        
     
}

/*
input for bestFit 

50 200 70 115 15
100 10 35 15 23 6 25 55 88 40

*/