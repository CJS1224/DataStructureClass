#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int end;
    int weight;
} t;

int n;
vector<node>q[500001];
int dis[500001];
bool vis[500001];

void ShortestPath(int start, int end)
{
    memset(vis, false, sizeof(vis));
    for(int i=0; i<=n; i++)
    {
        dis[i] = INF;
    }
    int len=q[start].size();
    for(int i=0; i<len; i++)
    {
        if(q[start][i].weight < dis[q[start][i].end] )
            dis[q[start][i].end]=q[start][i].weight;
    }

    vis[start]=true;

    for(int k=0; k<n-1; k++)
    {
        int pos, min=INF;
        for(int i=1; i<=n; i++)
        {
            if( !vis[i] && dis[i]<min )
            {
                min=dis[i];
                pos=i;
            }
        }

        vis[pos]=true;

        len=q[pos].size();
        for(int j=0; j<len; j++)
        {
            if( !vis[q[pos][j].end] && dis[ q[pos][j].end ]>q[pos][j].weight+dis[pos] )
                dis[q[pos][j].end ] = q[pos][j].weight + dis[pos];
        }
    }
    cout<<endl<<"the shortest distance is "<<dis[end]<<endl;
}


int main()
{
    int m;
    cout<<"please input the amount of nodes and edges:"<<endl;
    cin>>n>>m;

    for(int i=0; i<=n; i++)
        q[i].clear();
    cout<<endl<<"please key in the begin-node, the end-node, and the weight"<<endl;

    for(int i=0; i<m; i++)
    {
        int begin,end, weight;
        cin>>begin>>end>>weight;
        t.end=end;
        t.weight=weight;
        q[begin].push_back(t);

        t.end=begin;
        t.weight=weight;
        q[end].push_back(t);
    }

    int start, end;
    cout<<endl<<"please key in the starting node and the ending node of the whole path."<<endl;
    cin>>start>>end;

    ShortestPath(start, end);
    return 0;
}
