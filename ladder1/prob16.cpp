#include <iostream>
#include <bits/stdc++.h>
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
    
        ll n,res=0;
        ll num[4];
        for(ll i=0;i<4;i++)
            cin>>num[i];
        cin>>n;
        ll sets=(1<<4)-1; //b/c there are 4 numbers and total no. of sub seqences will be 2^4 -1 for excluding empty set.
        for(ll i=1;i<=sets;i++)
        {
            ll denom=1;
            ll setbits=__builtin_popcount(i); // built in funtion which returns no. of set bits
            for(ll j=0;j<4;j++)
            {
                if(i&(1<<j))
                {
                    denom=(denom*num[j])/__gcd(denom,num[j]); // we are using lcm to dertermine total number of numbers which are divisible ans less than n;
                }   
            }
            if(setbits&1)
            {
                res+=n/denom;
            }
            else
            {
                res-=n/denom;
            }
        }
        cout<<res<<endl;
 return 0;
}
