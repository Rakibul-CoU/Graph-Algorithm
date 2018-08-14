#include<bits/stdc++.h>

using namespace std;

#define Black 1
#define White 0

vector<int> vec[1000010];
int visit[1000010];

void DFS(int source)
{
    if(visit[source] == Black)
        return;
    visit[source] = Black;
    int len=vec[source].size();
    for(int i=0;i<len;i++)
    {
        DFS(vec[source][i]);
    }
}

int main()
{
    int node,u,n,v,source;
    cin>>node>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin>>source;
    DFS(source);
    for(int i=1;i<=node;i++)
    {
        cout<<visit[i]<<" ";
    }
    return 0;
}
