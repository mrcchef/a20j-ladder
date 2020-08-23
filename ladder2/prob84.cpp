#include <iostream>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <climits>
// #include <math.h>
// #include <string>
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
    ll n,v;
    cin>>n>>v;
    ll arr[3005]={0},mx=-1;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        arr[a]+=b;
        mx=max(mx,a);
    }
    ll res=0;
    for(ll i=1;i<=mx+1;i++)
    {
        ll x=v;
        if(arr[i-1]>=x)
        {
            res+=x;
            arr[i-1]-=x;
        }
        else
        {
            res+=arr[i-1];
            x-=arr[i-1];
            arr[i-1]=0;
            if(arr[i]>=x)
            {
                res+=x;
                arr[i]-=x;
            }
            else
            {
                res+=arr[i];
                x-=arr[i];
                arr[i]=0;
            }
        } 
    }
    cout<<res<<endl;
 return 0;
}
