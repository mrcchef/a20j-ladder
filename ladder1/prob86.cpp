#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <string>
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

bool comp(pair<ll,ll> &p1,pair<ll,ll> &p2)
{
    if(p1.first>p2.first)
        return true;
    else if(p1.first==p2.first)
        return p1.second<p2.second;
    return false;
}

int main()
{
        ll n,k,x,y;
        cin>>n>>k;
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++)
        {
            cin>>x>>y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end(),comp);
        // cout<<endl;
        // for(auto it=v.begin();it!=v.end();it++)
        //     cout<<it->first<<" "<<it->second<<endl;
        ll i=1;
        auto it1=v.begin();
        ll cnt=1;
        for(auto it=it1+1;it!=v.end();it++)
        {
            if(it->first==it1->first && it->second==it1->second)
            {
                cnt++;
            }
            else
            {
                it1=it;
                if(i>=k)
                {
                    cout<<cnt<<endl;
                    return 0;
                }    
                cnt=1;
            }
            i++;
        }
        cout<<cnt<<endl;
    
 return 0;
}
