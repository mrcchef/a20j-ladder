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

bool check(ll val,ll cnt1,ll cnt2,ll x,ll y)
{
    ll div_x,div_y,both,other;
    div_x=val/x;
    div_y=val/y;
    both=val/(x*1LL*y);
    other=val-div_x-div_y+both;
    
    ll req1=div_y-both;
    ll req2=div_x-both;
    
    cnt1=req1<cnt1?cnt1-req1:0;
    cnt2=req2<cnt2?cnt2-req2:0;

    if(cnt1+cnt2>other)
        return false;
    
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll cnt1,cnt2,x,y;
        cin>>cnt1>>cnt2>>x>>y;
        ll st=0;
        ll ed=LONG_MAX;
        ll ans=LONG_MAX;
        while(st<=ed)
        {
            ll mid=(st+ed)/2;
            // deb(mid);
            if(check(mid,cnt1,cnt2,x,y))
            {
                ed=mid-1;
                ans=min(ans,mid);
            }
            else
            {
                st=mid+1;
            }
            // deb(ans);
        
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