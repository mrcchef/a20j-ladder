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
const long mod = 1e9+7;

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
// Explanation
// https://www.youtube.com/watch?v=ccHyS64x6NQ

ll dp[2005][2005]; // state of DP is dp[i][k] where i denotes number i and k denotes the length of the subsequence starting from number i 
                    // and dp[i][k] store total number of possible subsequence such that every jth number divides (j+1)th number

ll solve(ll n,ll k,ll i)
{
    // when remaning length become equal to 1 is means we have find one subsequence
    if(k==0)
        return 1;
    // if solution already exist
    if(dp[i][k]!=-1)
        return dp[i][k];
    ll ans=0;
    // now we are checking for a subsequence which start from i and of length k and we will iterate to all the possible multiple of i 
    // such that the subsequence of required condition is created
    for(ll j=i;j<=n;j+=i)
    {
        if(j%i==0)
        {
            ans+=solve(n,k-1,j)%mod;
            ans=ans%mod;
        }
    }
    return dp[i][k]=ans;
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    ll res=solve(n,k,1);
    cout<<res<<"\n";

 return 0;
}
