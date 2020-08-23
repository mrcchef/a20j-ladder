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
#define pb puah_back
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


int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[n+1];
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll t,v,x,y,q,increase=0;
    while(m--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>v>>x;
            a[v]=x-increase; /// b/c when we add increase in future then the past incremented value will be neutralised and only those incremented value will be added
                             // which are incemented after this assignment
        }
        else if(t==3)
        {
            cin>>q;
            cout<<a[q]+increase<<endl;
        }
        else
        {
            cin>>y;
            increase+=y;
        }
    }
 return 0;
}
