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

class customer
{
    public:
        ll id;
        ll c,p;
        
};

class owner
{
    public:
        ll id,cap;
};

class relation
{
    public:
        ll idt,idc;
};

bool compare1(customer &c1,customer &c2)
{
    return c1.p>c2.p;
}

bool compare2(owner &o1,owner &o2)
{
    return o1.cap<o2.cap;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    vector<customer> vp;
    // lst(n,{0,0});
    fo(i,n)
    {
        customer v;
        cin>>v.c>>v.p;
        v.id=i+1;
        vp.pb(v);
    }
    vector<owner> on;
    ll k;
    cin>>k;
    fo(i,k)
    {
        owner v;
        cin>>v.cap;
        v.id=i+1;
        on.pb(v);
    }
    sort(vp.begin(),vp.end(),compare1);
    sort(on.begin(),on.end(),compare2);
    bool check[n]={false};
    ll cnt=0,cst=0,prev=0;
    vector<relation> tk; 
    fo(i,k)
    {
        ll cap=on[i].cap,mx_cost=INT_MIN,in=-1;
        for(ll j=0;j<n;j++)
        {
            if(check[j] || vp[j].c>cap)
                continue;
            if(mx_cost<vp[j].p)
            {
                mx_cost=vp[j].p;
                in=j;
            }
        }
        if(in!=-1)
        {
            cst+=mx_cost;
            cnt++;
            relation v;
            v.idc=vp[in].id;
            v.idt=on[i].id;
            check[in]=true;
            tk.pb(v);
        }
        prev=on[i].cap;
    }
    cout<<cnt<<" "<<cst<<endl;
    for(i=0;i<cnt;i++)
    {
        cout<<tk[i].idc<<" "<<tk[i].idt<<endl;
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