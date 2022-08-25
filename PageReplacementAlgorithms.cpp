#include <bits/stdc++.h>

using namespace std;

int pages, frames, n;
vector <int> refString;


void FIFO() // not working
{
    int sim[frames][pages];
    memset(sim, -1, sizeof(sim));

    int fault= 0;
    deque <int> inMem;

    for (int j = 0; j < n; j++) 
    {
        bool found = false;
        for (int i = 0; i < inMem.size(); i++)
        {
            if (sim[i][j-1] == refString[j])
            {
                found = true;
                break;
            }
        }

        if(!found && inMem.size() == frames)
        {
            fault++;
            for(int k = 0; k < inMem.size(); k++)
            { 
                sim[k][j] = sim[k][j-1];
                cout << sim[k][j] << *inMem.begin() <<endl;
                
                if (sim[k][j] == inMem.front())
                {
                    sim[k][j] = refString[j];
                    inMem.pop_front();
                    inMem.push_back(refString[j]);
                }
            }
            cout << endl;
        }
        else if (!found && inMem.size() < frames)
        {
            fault++;
            for(int k = 0; k < inMem.size(); k++)
            { 
                sim[k][j] = sim[k][j-1];
            }
            sim[inMem.size()][j] = refString[j];
            inMem.push_back(refString[j]);
            
        }
        
    }
    cout << "in here 7";
    cout << "Number of page fault using FIFO Page replacement Algorithm: " << fault << endl;;
    cout << "Page Fault Rate: " << fault*100/n << "%" << endl;;
    for(auto i = 0; i < frames; i++)
    {
        for(auto j = 0; i < n; j++)
        {
            if (sim [i][j] == -1)
            {
                cout << "  ";
            }
            else 
            {
                cout << sim[i][j] << " ";
            }
            
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cout << "Number of Pages: ";
    cin >> pages; 
    
    cout << "Number of Page References: ";
    cin >> n;

    cout << "References String: ";
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        refString.push_back(in);
    }
    cout << endl;
    
    cout << "Number of Memory Page Frame: ";
    cin >> frames;

    FIFO();

    return 0;
}

/*
8 
22 
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1 
3 
*/