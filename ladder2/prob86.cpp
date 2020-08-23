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

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    if(n<=3)
    {
        cout<<"no"<<endl;
        return 0;
    }
    
    ll flag=0;

    for(ll i=1;i<n;i++)
    {
        ll x1=min(a[i-1],a[i]);
        ll x2=max(a[i-1],a[i]);
        for(ll j=1;j<n;j++)
        {
            ll x3=min(a[j-1],a[j]);
            ll x4=max(a[j],a[j-1]);
            if(x1<x3 && x3<x2 && x2<x4)
            {
                flag=1;
                break;
            }
            if(x3<x1 && x1<x4 && x4<x2)
            {
                flag=1;
                break;
            }
        }
        
    }
    if(flag==1)
        cout<<"yes";
    else 
        cout<<"no";
    cout<<endl;
 return 0;
}
