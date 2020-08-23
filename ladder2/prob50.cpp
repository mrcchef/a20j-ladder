#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
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

bool comp(ll a,ll b
{
    return a<b;
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    //  for(ll i=0;i<n;i++)
    //     cout<<v[i]<<" ";
    // cout<<endl;
    for(ll i=0;i<(v.size()/2);i+=2)
        swap(v[i],v[v.size()-i-1]);    
    for(ll i=0;i<n;i++)
        cout<<v[i]<<" ";
 return 0;
}
