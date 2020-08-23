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

bool compare(pii p1,pii p2)
{
    if(p1.second==p2.second)
    {
        return p1.first>p2.first;
    }
    return p1.second<p2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j=-1,mn=INT_MAX;
    char ch[]="123456789";
    string s;
    cin>>n;
    if(n==0)    
    {
        cout<<-1;
        return 0;
    }
    ll vp[9];
    fo(i,9)
    {
        cin>>vp[i];
    }
    fo(i,9)
    {
        if(mn>=vp[i])
        {
            j=i;
            mn=vp[i];
        }
    }
    if(n<mn)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll time=n/mn;
    while(time--)
    {
        s+=ch[j];
    }
    ll rem=n%mn;
    // deb(rem);
    i=0;
    while(i<s.size())
    {
        ll val=s[i]-'0';
        // deb(val);
        for(ll j=8;j>val-1;j--)
        {
            if(rem+vp[val-1]>=vp[j])
            {
                s[i]=ch[j];
                rem=rem+vp[val-1]-vp[j];
                // deb(rem);
                break;
            }
        } 
        i++;
    }
    cout<<s<<endl;
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