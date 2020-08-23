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

// This is a quite simple question
// we have to maximise scoreA-scoreB
// for maximisation, our goal is to maximise scoreA and minimise scoreB and also if there difference become same then 
// then if condiser maximisation of scoreA.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,i,res1,res2,mx=INT_MIN;
    vi vn,vm;
    cin>>n;
    set<ll> s; // to get all the values that are present in both array so that we can check for all elements.
    fo(i,n)
    {
        ll x;
        cin>>x;
        s.insert(x);
        vn.pb(x);
    }
    cin>>m;
    fo(i,m)
    {
        ll x;
        cin>>x;
        s.insert(x);
        vm.pb(x);
    }
    sort(vn.begin(),vn.end());
    sort(vm.begin(),vm.end());
    vi v(s.begin(),s.end());
    ll j=0,a,b,x;
    res1=3*n;
    res2=3*m;
    mx=res1-res2;
    while(j<v.size())
    {
        ll in=upper_bound(vn.begin(),vn.end(),v[j])-vn.begin();
        ll pA=(in)*2+(n-in)*3,pB;
        ll in2=upper_bound(vm.begin(),vm.end(),v[j])-vm.begin();
        pB=(in2)*2+(m-in2)*3;
        if(mx<pA-pB) // for maximisation for difference of score
        {
            res1=pA;
            res2=pB;
            mx=res1-res2;
        }
        else if(mx==pA-pB) // if becomes equal then try to maximise scoreA
        {           
            if(pA>res1)
            {
                res1=pA;
                res2=pB;
            }  
        }   
        j++;
    }
    cout<<res1<<":"<<res2<<endl;
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