
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

// https://www.youtube.com/watch?v=BMilsTX0CW8

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll fa[n+1]={0},fb[n+1]={0};
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            fa[i+1]=fa[i]+1;
            fb[i+1]=fb[i];
        }
        else
        {
            fa[i+1]=fa[i];
            fb[i+1]=fb[i]+1;
        }
    }
    ll l=1,h=n,res=INT_MIN;
    while(l<=h)
    {
        ll mid=(l+h)/2,flag=0;
        for(ll j=0;j<=n-mid;j++)
        {
            ll mn=min(fa[j+mid]-fa[j],fb[j+mid]-fb[j]);
            if(mn<=k)
            {
                res=max(res,mid);
                // deb(res);
                l=mid+1;
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            h=mid-1;
        }
    }
    // for(ll i=0;i<n;i++)
    //     cout<<fa[i]<<" ";
    // cout<<endl;
    // for(ll i=0;i<n;i++)
    //     cout<<fb[i]<<" ";
    // cout<<endl;
    cout<<res<<endl;

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