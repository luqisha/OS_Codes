#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n;
    cin >>n;

    vector <int> req;

    for(int i = 0; i <n; i++)
    {
        int in;
        cin >> in;
        req.push_back(in);
    }

    int head;
    cin >>head;

    int movement= 0;

    while(!req.empty())
    {

        int diff= INT_MAX, index= -1, i;
        for(i = 0; i < req.size(); i++)
        {
            if (abs(req[i]-head) < diff)
            {
                diff = abs(req[i]- head);
                index = i;
            }

        }

        movement+= diff;
        head = req[index];
        req.erase(req.begin()+index);

    }

    cout << "Total Disk Movement: "<< movement << endl;

}

/*
8
98 183 37 122 14 124 65 67
53
*/
