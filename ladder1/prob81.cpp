#include <iostream>
#include <vector>
#include <string>
#include <map>
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

vector<ll> primes;

void cal_prime(ll n)
{
    ll len=sqrt(n);
    bool a[len+1]={false};
    a[2]=true;
    primes.push_back(2);
    for(ll i=3;i*i<=n;i+=2)
        a[i]=true;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(a[i])
        {
            primes.push_back(i);
            for(ll j=i*i;j*j<=n;j+=i)
                a[j]=false;
        }
    }
}

vector<ll> prime_factors(ll n)
{
    vector<ll> pf;
        for(ll i=0;i<primes.size();i++)
        {
            if(primes[i]*primes[i]>n)
                break;
            while(n%primes[i]==0)
            {
                pf.push_back(primes[i]);
                n=n/primes[i];
            }
        }
    if(n>1)
    {
        pf.push_back(n);
    }
    return pf;
}


int main()
{
        ll a,b,c;
        ll sm=0;
        cin>>a>>b>>c;
        ll n=a*b*c;
        cal_prime(n);
        vector<ll> v;
        for(ll i=1;i<=a;i++)
            for(ll j=1;j<=b;j++)
                for(ll k=1;k<=c;k++)
                    v.push_back(i*j*k);
                    
        // for(ll i=0;i<primes.size();i++)
        //     cout<<primes[i]<<" ";
        //     cout<<endl;
        for(ll i=0;i<v.size();i++)
        {
            ll div=1;
            vector<ll> pf=prime_factors(v[i]);
            map<ll,ll> m;
            for(ll i=0;i<pf.size();i++)
                m[pf[i]]++;
            for(auto it=m.begin();it!=m.end();it++)
                div*=((it->second)+1);
            sm+=div;
        }
        sm=sm%(1<<30);
        cout<<sm<<endl;

 return 0;
}
