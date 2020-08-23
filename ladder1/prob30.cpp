#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

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

       ll n,q,j;
       cin>>n;
       map<ll,ll> v;
       for(ll i=1;i<=n;i++)
       {
           cin>>j;
           v[j]=i;
       }
       cin>>q;
       ll sum1=0,sum2=0;
       for(ll i=0;i<q;i++)
       {
           cin>>j;
           ll x=v[j];
            sum1+=x;
            sum2+=n-x+1;
       }
       cout<<sum1<<" "<<sum2;
       

 return 0;
}
