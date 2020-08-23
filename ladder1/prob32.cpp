#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

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
   
        ll n,m,j;
        cin>>n>>m;
        vector<pair<ll,ll>> v;
        for(ll i=1;i<=n;i++)
        {
            cin>>j;
            v.push_back({i,j});
        }
        pair<ll,ll>p;
        for(ll i=0;i<v.size();i++)
        {
            p=v[i];
            v[i].second-=m;
            if(v[i].second>0)
            {
                v.push_back(v[i]);
            }
        }
        cout<<p.first;
   
 return 0;
}
