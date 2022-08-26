#include <bits/stdc++.h>

using namespace std;
vector <int> refString;
int frames, pages;

void LRU() // idk why not working :"(
{
    stack <int> inMem, temp;
    int n = refString.size();
    int fault = 0, hit = 0;

    for(auto it = refString.begin(); it!=refString.end(); it++)
    {

        if (inMem.empty())
        {
            inMem.push(*it);
            fault++;
        }
        else if (inMem.top() == *it)
        {
            hit++;
            continue;
        }
        else
        {
            while (inMem.top() != *it || !inMem.empty())
            {
                temp.push(inMem.top());
                inMem.pop();
            }

            if (inMem.empty())
            {
                while(!temp.empty())
                {
                    inMem.push(temp.top());
                    temp.pop();
                }
                inMem.push(*it);
                fault++;
            }
            else
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

    }

    cout << "Page fault: " << fault << endl;
    cout << "Page hit: " << hit << endl;
    cout << "Page fault rate : " << (fault / n) * 100 << endl;

}


int main()
{
    cout << "Number of Page Requests: ";
    cin >> pages; 

    for (int i = 0; i < pages; i++)
    {
        int input;
        cin >> input;
        refString.push_back(input);
    }    

    cout << refString.size() << endl;
    
    cout << "Number of Memory Page Frame: ";
    cin >> frames;

    LRU();

    return 0;
}

/*

22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3

*/