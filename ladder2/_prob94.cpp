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

bool compare(pair<ll,ll> p1,pair<ll,ll> p2)
{
    if(p1.first==p2.first)
        return p1.second>p2.second;
    return p1.first>p2.first;
}

//This is based on 1-DP

int main()
{
    ll n,mx=-1;
    cin>>n;
    vi v(n,0),s(100005,0);
    ll i;
    fo(i,n)
    {
        cin>>v[i];
        // deb(v[i]);
        s[v[i]]+=v[i];
        mx=max(mx,v[i]);
    }
    vi res(100005,0);
    res[1]=s[1];
    // here the res[i] denotes the maximum sum till number i 
    // for res[i] we have two option either we does not involve sum of ith element then res[i]=res[i-1]
    // or if we involve then we can not have sum[i-1] so we will consider result till i-2 and then add sum[i] to it
    for(ll i=2;i<=mx;i++)
    {
        res[i]=max(res[i-1],res[i-2]+s[i]);
    }
    cout<<res[mx]<<endl;
 return 0;
}
