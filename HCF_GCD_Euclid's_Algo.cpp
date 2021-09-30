#include "bits/stdc++.h"
typedef long long int ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin>>a>>b;

    a = abs(a);
    b = abs(b);

    if(b>a){
        swap(a,b);
    }

    ll c = 0;

    while(b!=0)
    {
        c = a%b;
        a = b;
        b = c;
    }

    cout<<a<<"\n";

    return 0;
}