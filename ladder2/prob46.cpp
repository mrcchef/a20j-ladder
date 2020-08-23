#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    ll l,r;
    cin>>l>>r;
    ll sm=0;
    ll dl=floor(log10(l))+1;
    ll dr=floor(log10(r))+1;
    // cout<<dl<<" "<<dr;
    vector<ll> v;
    for(ll i=dl;i<=dr+1;i++)
    {
        for(ll j=1;j<=(1<<i);j++)
        {
            ll k=j,val=0,p=0;
            while(p<i)
            {
                if(k&1)
                {
                    val=val*10+7;
                }
                else
                {
                    val=val*10+4;
                }
                k=k>>1;
                p++;
            }
            v.push_back(val);
        }
    }
    sort(v.begin(),v.end());
    // cout<<endl;
    // for(ll i=0;i<v.size();i++)
    //     cout<<v[i]<<" ";
    // cout<<endl;
    ll k;
    ll i=0;
    while(l<=r)
    {
        if(v[i]>=l)
        {
            k=v[i]-l+1;
            if(k<(r-l+1))
                sm+=k*v[i];
            else
            {
                sm+=(r-l+1)*v[i];
            }
            l=v[i]+1;     
        }
        i++;
    }
    cout<<sm<<endl;
    
 return 0;
}
