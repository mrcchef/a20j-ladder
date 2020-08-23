#include <iostream>
#include <vector>
#include <map>
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
    
        ll n;
        cin>>n;
        map<ll,ll> m;
        ll j;
        for(ll i=0;i<n;i++)
        {
            cin>>j;
            m[j]++;
        }
        auto it=m.begin();
        for(it;it!=m.end();it++)
        {
            ll x=it->second;
            if(n-x<x-1)
            {
                cout<<"NO"<<endl;
                return 0;
            }

        }
        if(it==m.end())

            cout<<"YES";
            cout<<endl;

 return 0;
}
