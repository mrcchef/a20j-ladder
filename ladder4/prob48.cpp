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

ll row[]={0,0,1,-1};
ll col[]={1,-1,0,0};

ll check(vector<string> &v,ll i,ll j,ll n,ll m,ll turn,ll total,pii p)
{
    if(i<0 || j<0 || i>=n || j>=m || turn>1 || v[i][j]=='W')
        return 0;
    
    for(ll k=0;k<4;k++)
    {
        if(p.first==row[k] && p.second==col[k])
            check(v,i+row[k],j+col[k],n,m,turn,total+1,p);
        else
            check(v,i+row[k],j+col[k],n,m,turn+1,total+1,{row[k],col[k]});
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<string> v;
    fo(i,n)
    {
        string s;
        cin>>s;
        v.pb(s);
    }
    for(ll i=0;i<n;i++)
    {
        string s;
        for(ll j=0;j<m;j++)
        {
            if(s[j]=='B')
            {

            }
        }
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