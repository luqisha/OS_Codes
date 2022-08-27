// created by 190104140_Ashiq at 2022-08-27 04:09.
// github.com/luqisha

#include <bits/stdc++.h>

using namespace std;

vector <int> refString;
int frames, pages;
int simOutput[50][100];

stack <int> inMem, temp;


void generateSimulation(int colIndex)
{
    int i = 0;
    while(!inMem.empty()) //iterate through inMem stack using temp stack
    {
        
        simOutput[i++][colIndex] = inMem.top();
        temp.push(inMem.top());
        inMem.pop();
    }

    while(!temp.empty()) //restore inMem stack
    {
        inMem.push(temp.top());
        temp.pop();
    }
    
}


void LRU() 
{
    int n = refString.size();
    int fault = 0, hit = 0;

    for(auto i = 0; i < refString.size(); i++)
    {
        if (inMem.empty()) //if memory frames are empty then just push into inMem stack
        {
            inMem.push(refString[i]);
            fault++;
        }
        else if (inMem.top() == refString[i]) //if top frame contains requested page
        {
            hit++;
            continue;
        }
        else
        {
            while (!inMem.empty() && (inMem.top() != refString[i] )) //searching inMem stack for requested page
            {
                temp.push(inMem.top());
                inMem.pop();
            }

            if (inMem.empty()) //page not found in inMem stack
            {
                if(temp.size() >= frames) //keeping the size of the stack fixed to num of frames
                {
                    temp.pop();
                }
                
                while(!temp.empty())
                {
                    inMem.push(temp.top());
                    temp.pop();
                }
                inMem.push(refString[i]);
                fault++;
            }
            else //page found in inMem stack
            {
                int x = inMem.top();
                inMem.pop();
                while(!temp.empty())
                {
                    inMem.push(temp.top());
                    temp.pop();
                }
                inMem.push(x);
                hit++;
            }
            
        }

        generateSimulation(i);

    }

    cout << endl;
    cout << "Page Fault: " << fault << endl;
    cout << "Page Hit: " << hit << endl;
    cout << "Page Fault Rate : " << ((float)fault / n) * 100 <<" %" << endl;

}


int main()
{
    memset(simOutput, -1, sizeof(simOutput));

    cout << "Number of Page Requests: ";
    cin >> pages; 

    cout << "Reference String: ";
    for (int i = 0; i < pages; i++)
    {
        int input;
        cin >> input;
        refString.push_back(input);
    }    

    cout << "Number of Memory Page Frame: ";
    cin >> frames;


    LRU();

    cout << endl << "Simulation Output ::" << endl;
    for (int i = 0; i < frames; i++)
    { 
        for (int j = 0; j < pages; j++)
        {
            if (simOutput[i][j] == -1)
            {
                cout << "  ";
            }
            else
            {
                cout << simOutput[i][j] << " " ;
            }
        }
        cout << endl;
    }
    cout << endl;
    

    return 0;
}

/*

22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3

*/