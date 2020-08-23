#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <set>
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
        ll j,i;
        vector<ll> s;
        for(i=0;i<n;i++)
        {
            cin>>j;
            s.push_back(j);
        }
        j=1;
        ll res=0;
        sort(s.begin(),s.end());
        for(ll i=0;i<s.size();i++)
        {
            res+=abs(i+1-s[i]);
        }
        cout<<res<<endl;
    
 return 0;
}
