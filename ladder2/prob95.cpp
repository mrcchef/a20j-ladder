#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <bitset>
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

const ll n=1000005;
bitset<1000005> bit;
vi primes;
void seive()
{
    // primes.pb(1);
    bit.set();
    bit[0]=bit[1]=0;
    for(ll i=2;i<=n;i++)
    {
        if(bit[i])
        {
            primes.pb(i);
            for(ll j=i*i;j<=n;j+=i)
                bit[j]=0;
        }
    }
    // bit[1]=1;
}

int main()
{
    seive();
    ll n,m;
    cin>>n>>m;
    ll a[n][m],b[n][m];
    memset(b,0,sizeof(b));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(bit[a[i][j]]==0)
            {
                auto ub=upper_bound(primes.begin(),primes.end(),a[i][j]);
                b[i][j]=*ub-a[i][j];
            }
        }    
    }
    ll res_c=INT_MAX,res_r=INT_MAX,temp;
    for(ll i=0;i<n;i++)
    {
        temp=0;
        for(ll j=0;j<m;j++)
        {
            // cout<<b[i][j]<<" ";
            temp+=b[i][j];
        }
        // cout<<endl;
        res_r=min(temp,res_r);
    }
    for(ll i=0;i<m;i++)
    {
        temp=0;
        for(ll j=0;j<n;j++)
        {
            temp+=b[j][i];
        }
        res_c=min(temp,res_c);
    }
    ll res=min(res_c,res_r);
    cout<<res<<endl;

 return 0;
}
