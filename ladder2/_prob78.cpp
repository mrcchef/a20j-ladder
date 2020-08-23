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

bool compare(ll v1,ll v2)
{
    return v1>v2;
}

ll dp[5005][5005];
ll mark[5005][5005];

ll solve(ll index,ll n,ll k,vi range_sum,ll m)
{
    if(index>n-m && k>0)
        return -1;
    if(k==0) 
        return 0;

    if(mark[index][k]==1)
        return dp[index][k];

    ll ans1,ans2;
    
    ans1=solve(index+1,n,k,range_sum,m); //If we are not considering that index then we will increase the index
    
    ans2=solve(index+m,n,k-1,range_sum,m)+range_sum[index]; //If we are considering that index of range_sum then the next index would be i+m
    
    dp[index][k]=max(ans1,ans2);
    mark[index][k]=1;

    return dp[index][k];

}

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vi v;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    vi r;
    ll sm=0;
    for(ll i=0;i<m;i++)
    {
        sm+=v[i];
    }
    r.pb(sm);
    for(ll i=1;i<=n-m;i++)
    {
        sm=sm-v[i-1]+v[i-1+m];
        // deb(sm);
        r.pb(sm);
    }
    memset(mark,-1,sizeof(mark));
    memset(dp,0,sizeof(dp));
    ll ans=solve(0,n,k,r,m);
    cout<<ans<<endl;
    // for(ll i=0;i<n-m+1;i++)
    //     cout<<r[i]<<" ";
    // cout<<endl;

 return 0;
}
