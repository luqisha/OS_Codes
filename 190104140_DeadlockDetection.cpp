#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void addEdge(vector<char> adj[], char x, char y)
{
    adj[x].push_back(y);
}

bool isDeadLock(vector<char> adj[], int V)
{
    map<char, int> inDegree (V, 0);
    int count = 1;

    for(int i = 0; i< V; i++)
    {
        for(int j= 0 ; j < adj[i].size(); j++)
        {
            char x = adj[i][j];
            auto itr = inDegree.find(x);
            itr->second++;
        }
    }

    queue<char> q;
    for (auto itr = inDegree.begin(); itr != inDegree.end(); i++)
    {

        if (itr->second == 0)
            q.push(itr->first);
    }


    while(!q.empty())
    {
        char curr = q.pop();

        for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++)
        {
            auto itr_inDegree = inDegree.find[*itr];
            if (itr_inDegree.second == 0)
                q.push(*itr);
                count++;
        }
    }

    if(count == V)
    {
        return false;
    }   
    else
    {
        return true;
    }
        

}

void main()
{
    int nodes;
    cin >> nodes;

    vector <char> adj[nodes];
    map <char, vector <char>
    for(int i = 0; i< nodes; i++)
    {
        char x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }

    if(isDeadLock(adj, nodes))
        cout << "There is Deadlock";
    else
        cout << "No Deadlock";


}

/*
sample input

14
A G
G B
B H
K B
C K
P C
L B
D L
Q D
L E
M E
E N
N F
F Q

*/
