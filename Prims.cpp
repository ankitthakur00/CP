#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v;
    cin>>v;
    vector<vector<int>>graph(v,vector<int>(v));
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        cin>>graph[i][j];
    }
}