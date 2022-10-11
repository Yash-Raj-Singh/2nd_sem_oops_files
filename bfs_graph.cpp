#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

int main()
{
    for(int i=0; i<N; i++)
    {
        vis[i] = 0;
    }

    int v,e;
    cin>>v>>e;

    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;


        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;

    q.push(0);
    vis[0] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout<<curr<<" ";

        for(auto x = adj[curr].begin(); x!= adj[curr].end(); x++)
        {
            if(!vis[*x])
            {
                vis[*x] = true;
                q.push(*x);
            }
        }
    }

    return 0;
}