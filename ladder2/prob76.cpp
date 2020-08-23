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

int main()
{
    string s;
    cin>>s;
    vi v;
    v.push_back(0);
    for(ll i=0;i<s.size();i++)
    {
        ll x=v[i];
        if(s[i]==s[i+1])
        {
            x++;
        }
        v.pb(x);
    }
    ll m,l,r;
    cin>>m;
    while(m--)
    {
        cin>>l>>r;
        ll res;
        res=v[r-1]-v[l-1];
        cout<<res<<endl;
    }
 return 0;
}
