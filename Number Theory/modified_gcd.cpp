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

vi divisors(ll n)
{
    set<ll> s;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            s.insert(i);
            s.insert(n/i);
        }
    }
    vi v(s.begin(),s.end());
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b,q;
    cin>>a>>b;
    ll gcd=__gcd(a,b);
    vi v=divisors(gcd);
    mii m;
    for(auto x:v)
        m[x]++;
    cin>>q;
    while(q--)
    {
        ll l,r,ans=-1;
        cin>>l>>r;
        auto it=lower_bound(v.begin(),v.end(),l);
        while(*it<=r && it!=v.end())
        {
            if(m[*it]!=0)
                ans=*it;
            it++;
        }
        cout<<ans<<endl;
    }
 return 0;
}


// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     ll a,b,q;
//     cin>>a>>b;
//     vi va,vb;
//     mii ma;
//     va=divisors(a);
//     vb=divisors(b);
//     for(auto x:va)
//         ma[x]++;
//     // for(auto x:vb)
//     //     cout<<x<<" ";
//     // cout<<endl;
//     cin>>q;
//     while(q--)
//     {
//         ll l,r,ans=-1;
//         cin>>l>>r;
//         auto it=lower_bound(vb.begin(),vb.end(),l);
//         while(*it<=r && it!=vb.end())
//         {
//             if(ma[*it]!=0)
//                 ans=*it;
//             it++;
//         }
//         cout<<ans<<endl;
//     }
//  return 0;
// }
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