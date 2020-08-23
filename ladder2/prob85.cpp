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

void solve(ll &a,ll cnt[])
{
    while(a!=1)
    {
        if(a%2==0)
        {
            a=a/2;
            cnt[0]++;
        }
        else if(a%3==0)
        {
            a=a/3;
            cnt[1]++;
        }
        else if(a%5==0)
        {
            a=a/5;
            cnt[2]++;
        }
        else
        {
            break;
        }  
    }
}

int main()
{
    ll a,b;
    cin>>a>>b;
    ll cnta[3]={0},cntb[3]={0};
    solve(a,cnta);
    solve(b,cntb);
    if(a!=b)
        cout<<-1;
    else
    {
        ll res=0;
        for(ll i=0;i<3;i++)
            res+=abs(cnta[i]-cntb[i]);
        cout<<res;
    }
    cout<<endl;

 return 0;
}
