#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> getMinMax(long long a[],int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        pair<ll,ll> pp=getMinMax(a,n);
        cout<<pp.first<<"   "<<pp.second<<endl;
    }
}




pair<long long,long long> getMinMax(long long a[],int n){
    ll mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mn=min(arr[i],mn);
        mx=max(a[i],mx);
    }
    return {mn,mx};
}


