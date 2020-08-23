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
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

// Good Question 
// we have to divide our array in 3 parts such that the sum of each part is equal
// ans we have calculate total number of ways to this

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,s=0,ans=0;
    cin>>n;
    ll a[n],cnt[n]={0},sm[n]={0};
    fo(i,n) 
    {
        cin>>a[i];
        s+=a[i];
    }
    // if sum is not divisible by 3 then not possible and array should minimum have 3 elements
    if(s%3!=0 || n<3)
    {
        cout<<0;
        return 0;
    }
    s=s/3;
    ll temp=0;
    // we will mark all the indexes j such subarray from index j to n can be the third part of the division 
    for(i=n-1;i>=0;i--)
    {
        temp+=a[i];
        if(temp==s)
            cnt[i]=1;
    }  
    // here we can calculating total no. of possible subarrays for the third part from i to n 
    // i.e/ sum[i] denotes total possible subarrays form index i to n which can be satisfy for 3rd subarray
    sm[n-1]=cnt[n-1];
    for(i=n-2;i>=0;i--)
    {
        sm[i]=sm[i+1]+cnt[i];
    }
    // now from the begnning we are calculating first subarray form index 0 to i
    // now form each valid subarray that is sum of subarray is equal to 's' , we will add in ans the number of possible 3rd part from i+2
    // b/c we at least the size of 2nd array is 1, so we will skip the the i+1 index and add total no. of possible third subarray possible form
    // index i+2
    temp=0;
    for(i=0;i<n-2;i++)
    {
        temp+=a[i];
        if(temp==s)
        {
            ans+=sm[i+2];
        }
    }
    cout<<ans;
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
}
ll m_m(ll a,ll b,ll m) 
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res+=a; 
            res=res%m;
        }
        a=(a*2)%m;
        b=b/2;
    }
    return res;
}