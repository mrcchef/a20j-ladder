#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
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

ll digit_sum(ll n)
{
    ll sm=0;
    while(n>0)
    {
        sm+=n%10;
        n=n/10;
    }
    return sm;
}

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    vi v;
    for(ll i=1;i<=81;i++)
    {
        ll val=b*fxp(i,a,mod)+c;
        if(i==digit_sum(val))
        {
            if(val<1e9)
            v.pb(val);
        }
    }
    cout<<v.size()<<endl;
    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
 return 0;
}
