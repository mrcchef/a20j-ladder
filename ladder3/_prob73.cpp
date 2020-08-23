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
const ll mod = 1e8;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll k1,k2;
ll dp[101][101][11][11];

// dp is just memoisation of recurssion so that same case would not be solved

ll solve(ll n,ll m,ll K1,ll K2)
{
    // base case 
    // it means we have successfully created a possible combination of length n+m
    if(n+m==0)
        return 1;
    
    if(dp[n][m][K1][K2]!=-1)
        return dp[n][m][K1][K2];

    ll x=0,y=0;
    if(n>0 && K1>0) // when we have enough n and we have are under the limit of k1 then we can add footmen in the permuatation
        x=solve(n-1,m,K1-1,k2);

    if(m>0 && K2>0) // similarly as in case of footmen
        y=solve(n,m-1,k1,K2-1);
    
    return dp[n][m][K1][K2]=(x+y)%mod; // return total number of combinations formed
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k1>>k2;
    cout<<solve(n,m,k1,k2);
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