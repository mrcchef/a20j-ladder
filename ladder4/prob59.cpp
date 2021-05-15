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

ll N=1e6+10;

ll f[(ll)1e6+10];

void fact()
{
    f[0]=f[1]=1;
    for(ll i=2;i<N;i++)
    {
        f[i]=f[i-1]*i;
        f[i]=f[i]%mod;
    }
}

ll printNcR(ll n,ll x)
{
    ll v1=f[n];
    ll v2=f[n-x]*f[x];
    ll res=fxp(v2,mod-2,mod)*v1;
    return res;
}


bool check(ll val,ll a,ll b)
{
    while(val)
    {
        ll x=val%10;
        val/=10;
        if(x!=a && x!=b)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    fact();
    while(t--)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        if(a<b)
            swap(a,b);
        ll cnta=n,cntb=0;
        ll sm=n*a,ans=0;
        vi v;
        for(sm;sm>=n*b;sm=sm-a+b)
        {
            if(check(sm,a,b))
            {
                ans=(ans+(printNcR(n,cnta))%mod)%mod;
                // ans=ans%mod;
            }
            cnta--;
            cntb++;
        }
        cout<<ans<<endl;
    }
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