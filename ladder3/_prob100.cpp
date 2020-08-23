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
    ll n,i,j;
    cin>>n;
    ll a[n][n];
    fo(i,n)
        fo(j,n)
            cin>>a[i][j];
    ll d1[2*n],d2[2*n];
    memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d1[i+j]+=a[i][j]; // these two are the key of the question
            d2[i-j+n]+=a[i][j]; // i.e. to cal. secondary and primary diagonals.
        }
    }
    ll res1=INT_MIN,res2=INT_MIN;
    ll x1,x2,y1,y2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ll val=d1[i+j]+d2[i-j+n]-a[i][j];
            if((i+j)&1)
            {
                if(res1<val)
                {
                    res1=val;
                    x1=i;
                    y1=j;
                }
            }
            else
            {
                if(res2<val)
                {
                    res2=val;
                    x2=i;
                    y2=j;
                }
            }
        }
    }
    cout<<res1+res2<<endl;
    cout<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<endl;
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