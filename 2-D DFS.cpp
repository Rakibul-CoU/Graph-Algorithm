#include<bits/stdc++.h>

using namespace std;

#define White 0
#define Black 1

char s[1000][1000];

int visited[1000][1000];

int fx[8]={-1,+1,0,0,-1,-1,+1,+1};
int fy[8]={0,0,+1,-1,-1,+1,-1,+1};

void DFS(int i,int j,int row,int col)
{
    visited[i][j]=Black;
    for(int k=0;k<8;k++)
    {
        int res1=i+fx[k];
        int res2=j+fy[k];
        if(res1>=0 and res1<=row-1 and res2>=0 and res2<=col-1 and visited[res1][res2]==White and s[res1][res2]=='#')
        {
            DFS(res1,res2,row,col);
        }
    }
}

int countislands(int row,int col)
{
    int cnt=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(s[i][j]=='#' and visited[i][j]==White)
            {
                cnt++;
                DFS(i,j,row,col);
            }
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int row,col;
        cin>>row>>col;
        for(int i=0; i<row; i++)
        {
            cin>>s[i];
        }
        int res = countislands(row,col);
        cout<<res<<endl;
    }

    return 0;
}
