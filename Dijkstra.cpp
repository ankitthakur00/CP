#include<bits/stdc++.h>
const int n=9;
using namespace std;
int minvertax(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void dijkstra(int edges[n][n],int src)
{
    bool vis[n];
    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        vis[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        int minVertax=minvertax(dist,vis);
        vis[minVertax]=true;
        for(int j=0;j<n;j++){
        if(!vis[j] && edges[i][j] && dist[minVertax]!=INT_MAX && (edges[minVertax][j]+dist[minVertax])<dist[j])
        dist[j]=dist[minVertax]+edges[minVertax][j];
        }
    }
    for(int i=0;i<n;i++)
    cout<<i<<" "<<dist[i]<<endl;
}
int main()
{
    int edges[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 


    dijkstra(edges,0);
}