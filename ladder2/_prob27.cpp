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
    return p1.first<p2.first;
}

int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
        
    // }
    ll n,s;
    cin>>s>>n;
    ll flag=0;
    vector<pair<ll,ll>> vp;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        vp.pb({x,y});
    }
    ll i;
    sort(vp.begin(),vp.end(),compare);
    fo(i,n)
    {
        if(s>vp[i].first)
            s=s+vp[i].second;
        else
        {
            flag=1;
            break;
        }
        
    }
    if(flag==0)
        cout<<"YES";
    else   
        cout<<"NO";
    cout<<endl;
 return 0;
}
