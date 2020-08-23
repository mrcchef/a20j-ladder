#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
#include <map>
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

vector<ll> primes;

void prime(ll n)
{
    ll x=sqrt(n);
    bool p[x+1]={false};
    p[0]=p[1]=false;
    p[2]=true;
    primes.push_back(2);
    for(ll i=3;i*i<=n;i+=2)
        p[i]=true;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(p[i])
        {
            primes.push_back(i);
            for(ll j=i;j*j<=n;j+=i)
                p[j]=false;
        }
    }   
}

vector<ll> trial_division4(ll n) {
    vector<ll> factorization;
    for (ll d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

bool comp(ll a,ll b)
{
    return a>b;
}

int main()
{
    
        ll n;
        cin>>n;
        vector<ll> v,z;
        ll j;
        for(ll i=0;i<n;i++)
        {
            cin>>j;
            v.push_back(j);
            z.push_back(j);
        }
        sort(v.begin(),v.end(),comp);
        prime(v[0]);
        for(ll i=0;i<z.size();i++)
        {
            bool res=binary_search(primes.begin(),primes.end(),sqrt(z[i]));
            if(res)
                cout<<"YES";
            else
            {
                cout<<"NO";
            }
            cout<<endl;
        }
    
 return 0;
}
