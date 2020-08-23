#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    vector<pair<ll,ll>> v;
    ll i,j;
    for(ll i=0;i<n;i++)
    {
        cin>>j;
        v.push_back({j,i});
    }
    sort(v.begin(),v.end());
    map<ll,ll> freq,val;
    ll res=0;
    for(auto it=v.begin();it!=v.end();it++)
    {
        if(val[it->first]!=-1)
        {
            freq[it->first]++;
            if(freq[it->first]>1)
            {
                auto it1=prev(it);
                ll x=it->second-it1->second;
                if(val[it->first]==0)
                    val[it->first]=x;
                else
                {
                    if(val[it->first]!=x)
                    {
                        val[it->first]=-1;
                    }
                }
                
            }
        }
        
    }
    for(auto it=val.begin();it!=val.end();it++)
    {
        if(it->second!=-1)
            res++;
    }
    cout<<res<<endl;
    for(auto it=val.begin();it!=val.end();it++)
    {
        if(it->second!=-1)
            cout<<it->first<<" "<<it->second<<endl;
    }
 return 0;
}
