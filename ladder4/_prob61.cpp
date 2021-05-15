#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
// #define pb push_back
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll rqb,rqs,rqc;
        rqb=rqs=rqc=0;
        ll nb,ns,nc,pb,ps,pc,r;
        cin>>nb>>ns>>nc;
        cin>>pb>>ps>>pc;
        cin>>r;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='B')
                rqb++;
            else if(s[i]=='S')
                rqs++;
            else 
                rqc++;
        }
        ll c=INT_MAX;
        if(rqb!=0)
            c=min(c,nb/rqb);
        if(rqs!=0)
            c=min(c,ns/rqs);
        if(rqc!=0)
            c=min(c,nc/rqc);
        nb=nb-c*rqb;
        ns=ns-c*rqs;
        nc=nc-c*rqc;
        ll st=0,ed=1e12,ans=0;
        while(st<=ed)
        {
            ll mid=(st+ed)/2;
            ll val=0;
            if(rqb!=0)
                if(mid*rqb-nb>=0)
                    val+=(mid*rqb-nb)*pb;
            if(rqs!=0)
                if((mid*rqs-ns)>=0)
                val+=(mid*rqs-ns)*ps;
            if(rqc!=0)
                if(mid*rqc-nc>=0)
                val+=(mid*rqc-nc)*pc;
            if(val<=r)
            {
                ans=max(ans,mid);
                st=mid+1;
            }
            else
                ed=mid-1;
        }
        ans+=c;
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