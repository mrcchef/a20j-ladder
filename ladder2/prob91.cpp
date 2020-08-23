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

int main()
{
        ll n,k;
        cin>>n>>k;
        ll arr[n]; // input array
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        ll sum=0;
        for(ll i=0;i<k;i++) // creating first segment og length k
            sum+=arr[i];
        ll seg[n]={0};      // we are storing all the possible segments i.e n-k+1 segments and their index denotes the begnning index of segment
        seg[0]=sum;
        for(ll i=k;i<n;i++)
        {
            sum+=arr[i]-arr[i-k];
            seg[i-k+1]=sum;
        }
        vector<pair<ll,ll>> vp(n,{-1,-1}); // here we are storing the maximum segmnet till ith index
        // (k-1,{-1,-1})
        ll pos=-1,maxi=0;
        for(ll i=k-1;i<n;i++) // we have choosen i=k-1 b/c it is the end index of first segment
        {
            if(maxi<seg[i-k+1]) // we just check that is the ith segment has sum greator than the current max
            {
                maxi=seg[i-k+1];
                pos=i-k+1;          // if exist then update the value of maximun sum of segment and it beg. position
            }
            vp[i]={maxi,pos};       // storing the maximum val of sum of the segment and it's beg. position at till ith index
        }                           // where ith is the end index of the segment
        // for(ll i=0;i<n;i++)
        // {
        //     cout<<seg[i]<<" ";
        // }
        // cout<<endl;
        // for(ll i=0;i<vp.size();i++)
        // {
        //     cout<<i<<"->"<<vp[i].first<<" "<<vp[i].second<<endl;
        // }
        maxi=0;
        ll a=-1,b=-1;
        for(ll i=k;i<n-k+1;i++)
        {
            if(seg[i]+vp[i-1].first>maxi)  // then checking the two segment whose sum is maximal 
            {                               // for each b we will find the maximum sum segment till the b-1 ending index b/c segments are
                // deb(a);                  // non intersecting
                // deb(b);
                a=vp[i-1].second;
                b=i;
                maxi=seg[i]+vp[i-1].first;
            }
        }
        cout<<a+1<<" "<<b+1;

 return 0;
}
