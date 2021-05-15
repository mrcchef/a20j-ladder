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

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll check(ll a[],ll sm[],ll mid,ll n,ll k)
{
    for(ll i=mid;i<=n;i++)
    {
        if(a[i]*mid-(sm[i]-sm[i-mid])<=k)
            return a[i];
    }
    return LONG_LONG_MAX;
}

// Good Question on Binary search
// https://www.youtube.com/watch?v=VOFZAdwrCgs

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {   
        ll n,k,i;
        cin>>n>>k;
        ll a[n+1],sm[n+1]={0};
        fo(i,n)
        {
            cin>>a[i+1];
        }
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
            sm[i]=sm[i-1]+a[i];
        // for(i=0;i<=n;i++)
        //     cout<<sm[i]<<" ";
        // cout<<endl;
        ll st=1,ed=n,ans=0,val;
        while(st<=ed)
        {
            ll mid=(st+ed)/2;
            ll tm=check(a,sm,mid,n,k);
            if(tm!=LONG_LONG_MAX)
            {
                if(ans<mid)
                {
                    ans=mid;
                    val=tm;
                }
                st=mid+1;
            }
            else
            {
                ed=mid-1;
            }
        }
        cout<<ans<<" "<<val<<endl;

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