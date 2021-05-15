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
const double PI=3.14159265358979323846;

// Voice note is present for this question although logic is pretty simple

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
    int t=1;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<double> v;
        for(ll i=0;i<n;i++)
        {
            double x,y;
            cin>>x>>y;
            double val=atan2(y,x);
            // deb(val);
            if(val<0)
            {
                val+=2*PI;
            }
            v.pb(val);
        }
        sort(v.begin(),v.end());
        double res=10000;
        for(ll i=1;i<n;i++)
        {
            double val=2*PI-v[i]+v[i-1];
            // deb(v[i]);
            // deb(v[i-1]);
            // deb(val);
            res=min(res,val);
        }
        res=min(res,v[v.size()-1]-v[0]);
        // for(auto x:v)
        //     cout<<x<<" ";
        printf("%.101f\n",(res*180)/PI);
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