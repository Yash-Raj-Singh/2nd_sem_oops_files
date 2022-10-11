#include "bits/stdc++.h"

using namespace std;

int main()
{

    int n, m;
    cin>>n>>m;

    vector<int> dist(n+1, INT_MAX);

    vector<vector<pair<int, int>>> g(n+1);


    for(int i = 0; i<m; i++)
    {
        int u,v, w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int source;
    cin>>source;

    dist[source] = 0;

    // set<pair<int, int>> s;

    // s.insert({0, source});

    // while(!s.empty())
    // {
    //     auto x = *(s.begin());
    //     s.erase(x);

    //     for(auto it : g[x.second])
    //     {
    //         if(dist[it.first]>dist[x.second]+it.first)
    //         {
    //             s.erase({dist[it.first], it.first});
    //             dist[it.first] = dist[x.second]+it.first;
    //             s.insert({dist[it.first], it.first});
    //         }
    //     }
    // }

    priority_queue <pair<int, int>> pp;
    pp.push({source, 0});

    while(!pp.empty())
    {
        int f = pp.top().first;
        int l = pp.top().second;
        pp.pop();
        //printing as per priority
        cout<<l<<" ";
        for(auto k : g[f])
        {
            int r = k.first;
            int w = k.second;
            if(w+dist[f] < dist[r])
            {
                dist[r] = w+dist[f];
                pp.push({r, dist[r]});
            }
        }
    }
    //printing in sequence
    cout<<endl<<endl;
    for(int i = 1; i<=n; i++)
    {
        if(dist[i]<INT_MAX)
        {
            cout<<dist[i]<<" for "<<i<<"\n";
        }
        else{
            cout<<"-1"<<" ";
        }
    }

    return 0;
}