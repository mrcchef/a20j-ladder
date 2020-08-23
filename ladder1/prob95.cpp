#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
using namespace std;
#define ll long long int
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main()
{
    
        ll n,m,d,j;
        cin>>n>>m>>d;
        vector<ll> v;
        for(ll i=0;i<n*m;i++)
        {
            cin>>j;
            v.push_back(j);
        }
        ll x=v[0]%d;
        for(ll i=0;i<n*m;i++)
        {
            if(x!=v[i]%d)
            {
                cout<<-1;
                return 0;
            }
        }
        sort(v.begin(),v.end());
        ll median=v[(n*m-1)/2];
        ll res=0;
        for(ll i=0;i<n*m;i++)
        {
            ll val=abs(median-v[i])/d;
            res+=val;
        }
        cout<<res<<endl;
    
 return 0;
}
