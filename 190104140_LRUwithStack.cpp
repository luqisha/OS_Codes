#include <bits/stdc++.h>

using namespace std;
vector <int> refString;
int frames, pages;
void LRU()
{
    stack <int> inMem;
    int n = refString.size();

    for(auto it = refString.begin(); it!=refString.end(); it++)
    {
        auto index = find(inMem, inMem+frames, *it);

        if(index == inMeme+frames+1)
        {
            inMem.push(*it);
        }
        else
        {
            if(inMem.top() == *it)
            {
                continue;
            }
            else{
                vector <int> temp;
                for(auto it2 = inMem; it2!= index; it2++)
                {
                    

                    temp.push_back(inMem.top());
                    inMem.pop();
                }

                int x = temp.back();
                temp.pop_back();

                while(!temp.empty())
                {
                    inMem.push(temp.back());
                    temp.pop_back();
                }

                inMem.push(x);
            }   
        } 

        for(auto i = inMem; i!= index; i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }

    
}


int main()
{
    cout << "Number of Pages: ";
    cin >> pages; 
    
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

    LRU();

    return 0;
}