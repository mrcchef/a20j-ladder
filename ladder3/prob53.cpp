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
#define ll int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n+1][m+1];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    ll row[n+1],col[m+1];
    for(ll i=1;i<=n;i++)
        row[i]=i;
    for(ll i=1;i<=m;i++)
        col[i]=i;
    while(k--)
    {
        char s;
        ll x,y;
        cin>>s>>x>>y;
        if(s=='c')
        {
            ll t=col[x];
            col[x]=col[y];
            col[y]=t;
        }
        else if(s=='r')
        {
            ll t=row[x];
            row[x]=row[y];
            row[y]=t;
        }
        else
        {
            ll val=a[row[x]][col[y]];
            cout<<val<<"\n";
        }
    }
 return 0;
}
