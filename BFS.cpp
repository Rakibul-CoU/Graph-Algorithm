#include<bits/stdc++.h>

using namespace std;

#define white 0
#define black 1

int visited[1000010],level[1000010],parent[1000010];

vector<int> vec[1000020];

int node,edge;

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = black;
    level[source] = 0;
    parent[source] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int len = vec[u].size();
        for(int i=0; i<len; i++)
        {
            int v=vec[u][i];
            if(visited[v] == white)
            {
                q.push(v);
                visited[v] = black;
                level[v] = level[u]+1;
                parent[v] = u;
            }
        }
    }
}

int main()
{
    int u,v,source;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);///[u-->v]
        vec[v].push_back(u);///[v-->u]
    }
    cin>>source;
    BFS(source);
    for(int i=1; i<=node; i++)
    {
        cout<<"node = "<<i<<" visited = "<<visited[i]<<" level = "<<level[i]<<" parent = "<<parent[i]<<endl;
    }
    return 0;
}
