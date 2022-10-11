#include <bits/stdc++.h>

using namespace std;

const int n = 1e5+6;
vector<int> parent(n);
vector<int> sz(n);


void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if(v == parent[v])
    {
        return v;
    }

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if(a != b)
    {
        if(sz[a]<sz[b])
        {
            swap(a,b);
        }

        parent[b] = a;

        sz[a] += sz[b];
    }
}

int main()
{

    for(int i=0; i<n; i++)
    {
        make_set(i);
    }

    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;

        edges.push_back({u,v});
    }

    bool cycle = false;

    for(auto x : edges)
    {
        int u = x[0];
        int v = x[1];

        int k = find_set(u);
        int l = find_set(v);

        if(k == l)
        {
            cycle = true;
            break;
        }
        else{
            union_sets(u,v);
        }
    }

    if(cycle)
    {
        cout<<"Yes, there is a Cycle!\n";
    }
    else{
        cout<<"No, Cycle wasn't found!\n";
    }

    return 0;
}