#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define deb(x) cout << #x << "=" << x << endl
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

ll n,m;

ll solve(ll *a,vector<vector<ll>> v,ll i)
{
    for(ll j=0;j<3;j++)
    {
        if(a[v[i][j]]!=0)
        {
            return a[v[i][j]];
        }
    }
    return 0;
}

int main()
{
    cin>>n>>m;
    ll a[n+1]={0};
    vector<vector<ll>> v;
    for(ll i=0;i<m;i++)
    {
        vector<ll> t;
        for(ll j=0;j<3;j++)
        {
            ll x;
            cin>>x;
            t.pb(x);
        }
        v.push_back(t);
    }
    for(ll i=0;i<m;i++)
    {
        if(a[v[i][0]]==0 && a[v[i][1]]==0 && a[v[i][2]]==0)
        {
            a[v[i][0]]=1;
            a[v[i][1]]=2;
            a[v[i][2]]=3;
        }
        else if(a[v[i][0]])
        {
            if(a[v[i][0]]==1)
            {
               a[v[i][1]]=2;
               a[v[i][2]]=3; 
            }
            else if(a[v[i][0]]==2)
            {
                a[v[i][1]]=1;
                a[v[i][2]]=3;
            }
            else
            {
                a[v[i][1]]=2;
                a[v[i][2]]=1;
            }
            
        }
        else if(a[v[i][1]])
        {
            if(a[v[i][1]]==1)
            {
                a[v[i][2]]=3;
                a[v[i][0]]=2;
            }
            else if(a[v[i][1]]==2)
            {
                a[v[i][2]]=3;
                a[v[i][0]]=1;
            }
            else
            {
                a[v[i][2]]=1;
                a[v[i][0]]=2;
            }
        }
        else
        {
            if(a[v[i][2]]==1)
            {
                a[v[i][1]]=3;
                a[v[i][0]]=2;
            }
            else if(a[v[i][2]]==2)
            {
                a[v[i][1]]=3;
                a[v[i][0]]=1;
            }
            else
            {
                a[v[i][1]]=1;
                a[v[i][0]]=2;
            }
        }
    }
        for(ll i=1;i<=n;i++)
            cout<<a[i]<<" ";
    return 0;
}