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

bool check(ll h,ll r,ll n[],ll p[],ll cnt[])
{
    ll req[3],total=0;
    for(ll i=0;i<3;i++)
    {
        req[i]=max(0LL,(h*cnt[i]-n[i]));
        total+=req[i]*p[i];
    }
    return total<=r;
}
// This approch is based on Binary Search 
// Since the hamburger h1 which is larger than hamburger h2 such that h2>h1 so that cost for h2>cost for h1
// This is actually increasing function so we can use binary search
// The maximum number of hamburger is 1e14 so for convinient we take 1e15
 

int main()
{
    string s;
    cin>>s;
    ll n[3],p[3],cnt[3]={0};
    for(ll i=0;i<3;i++)
        cin>>n[i];
    for(ll i=0;i<3;i++)
        cin>>p[i];
    ll r,res=0;
    cin>>r;
    for(auto x:s)
    {
        if(x=='B')
            cnt[0]++;
        else if(x=='S')
            cnt[1]++;
        else
            cnt[2]++;
    }

    ll lh=0,hh=1e15;
    while(hh-lh>1)
    {
        ll mid=(lh+hh)/2;
        if(check(mid,r,n,p,cnt))
        {
            lh=mid;
        }
        else
        {
            hh=mid-1;
        }
    }
    if(check(hh,r,n,p,cnt))  
        cout<<hh;
    else
    {
        cout<<lh;
    }
    // cout<<endl;
    // while(hh>lh)
    // {
    //     ll mid=(lh+hh)/2;
    //     if(check(mid,r,n,p,cnt))
    //     {
    //         lh=mid;
    //     }
    //     else
    //     {
    //         hh=mid-1;
    //     }
    // }
    // cout<<hh;
    cout<<endl;


    
 return 0;
}



