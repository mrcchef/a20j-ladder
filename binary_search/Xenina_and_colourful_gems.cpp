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
const ll mod = 1e18;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

ll ans;

// https://www.youtube.com/watch?v=QK291sG19j0

void solve(vi &va,vi &vb,vi &vc,ll na,ll nb,ll nc)
{
    for(auto x:va)
    {
        ll in1,in2;
        in1=lower_bound(vb.begin(),vb.end(),x)-vb.begin();
        in2=upper_bound(vc.begin(),vc.end(),x)-vc.begin();
        if(in1==nb || in2==0)
            continue;
        in2--;
        ll y=vb[in1],z=vc[in2];
        ans=min(ans,fxp(x-y,2,mod)+fxp(y-z,2,mod)+fxp(x-z,2,mod));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=LONG_LONG_MAX;
        ll a,b,c,i;
        cin>>a>>b>>c;
        vi va,vb,vc;
        fo(i,a)
        {
            ll x;
            cin>>x;
            va.pb(x);
        }   
        fo(i,b)
        {
            ll x;
            cin>>x;
            vb.pb(x);
        }   
        fo(i,c)
        {
            ll x;
            cin>>x;
            vc.pb(x);
        }  
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end());
        sort(vc.begin(),vc.end());

        solve(va,vb,vc,a,b,c);
        solve(va,vc,vb,a,c,b);
        solve(vb,va,vc,b,a,c);
        solve(vb,vc,va,b,c,a);
        solve(vc,vb,va,a,b,a);
        solve(vc,va,vb,c,a,b);

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