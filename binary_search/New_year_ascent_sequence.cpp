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

bool compare(ll a,ll b)
{
    return a<=b;
}

// This is good question , editorial for this is enough 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j;
    cin>>n;
    vi fst,lst;
    fo(i,n)
    {
        ll len;
        cin>>len;
        vi v;
        fo(j,len)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        reverse(v.begin(),v.end());
        if(is_sorted(v.begin(),v.end()))
        {
            fst.pb(v.back());
            lst.pb(v[0]);
        }
    }
    sort(fst.begin(),fst.end());
    // for(auto x:fst)
    //     cout<<x<<" ";
    // cout<<endl;
    // for(auto x:lst)
    //     cout<<x<<" ";
    // cout<<endl;
    ll ans=0;
    for(i=0;i<lst.size();i++)
    {
        ll cnt=lower_bound(fst.begin(),fst.end(),lst[i],compare)-fst.begin();
        // deb(cnt);
        // deb(lst[i]);
        ans+=cnt;
    }
    // cout<<ans<<endl;
    cout<<n*n-ans<<endl;
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