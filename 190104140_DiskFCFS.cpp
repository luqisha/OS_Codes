#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> req;

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        req.push(in);
    }

    int head;
    cin >> head;

    int movement = 0;

    while(!req.empty())
    {

        movement += abs(head - req.front());
        head = req.front();

        req.pop();
    }

    cout << "Total Movement: " << movement << endl; 


}

/*
8
98 183 37 122 14 124 65 67
53
*/