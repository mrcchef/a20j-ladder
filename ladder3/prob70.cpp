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
#define vpi vector<pii>
#define vi vector<ll>
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

bool compare(pii p1,pii p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second<p2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,r,avg,i;
    cin>>n>>r>>avg;
    vpi vp;
    ll sm=0;
    fo(i,n)
    {
        ll a,b;
        cin>>a>>b;
        sm+=a;
        vp.pb({a,b});
    }
    sort(vp.begin(),vp.end(),compare);
    ll rem=avg*n-sm,cnt=0;
    if(rem>0)
    {
        for(ll i=0;i<vp.size();i++)
        {
            ll aval=r-vp[i].first;
            if(aval>0)
            {
                if(aval>rem)
                {
                    cnt+=rem*vp[i].second;
                    break;
                }
                else
                {
                    rem-=aval;
                    cnt+=aval*vp[i].second;
                }    
            }
        }
    }
    cout<<cnt<<endl;
    
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
