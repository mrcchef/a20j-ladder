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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,ans;
    ll dp[4005]={0};
    ll a[3];
    cin>>n;
    // f[n]=1;
    fo(i,3)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        ll res[3],flag=0;
        res[0]=res[1]=res[2]=-1;
        for(ll j=0;j<3;j++)
        {
            if(i-a[j]>=0)
                res[j]=dp[i-a[j]];
        }
        for(ll j=0;j<3;j++)
            if(res[j]!=-1)
                flag=1;
        if(flag==0)
            dp[i]=-1;
        else
        for(ll j=0;j<3;j++)
            dp[i]=max(dp[i],res[j]+1);
        // dp[i]+=1;
    }
    // for(i=0;i<=n;i++)
    //     cout<<dp[i];
    // cout<<endl;
    cout<<dp[n]<<endl;
    
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