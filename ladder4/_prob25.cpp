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

// Good Greedy problem

//Well you can call it a greedy algorithm, when we try to apply greedy by placing the heaviest block in bottom,
// a little problem occurs because of blocks of same strength for example in case of 10 2 2 1 1 0 0
// If you try to apply greedy by choosing the strongest block
// 10 2 2 1
// 1 0
// 0
// = 3 heaps
// Which is wrong answer as sometimes we lose opportunity to create lesser heaps,
// as in this case if we use the second 2 to make another heap we can do better
// 10 2 1 0
// 2 1 0
// = 2 heaps
// So I apply greedy in the reverse direction by picking the smallest strength brick and placing below it the next smallest brick, 
// this way the optimal number of heaps will be formed as in above example
// choose 0, then you need >= 1, choose 1, then you need >= 2, choose 2, then you need >= 3 choose 10
// repeat until you have chosen all the bricks

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i;
    cin>>n;
    ll check[n]={0};
    vi v;
    fo(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    ll cnt=0,res=0;
    while(cnt<n)
    {
        i=0;
        ll prev=-1,curr=0;
        while(i<n)
        {
            if(check[i]==0 && v[i]>=prev && v[i]>=curr)
            {
                if(prev==0 && v[i]==0)
                {
                    i++;
                    continue;
                }    
                curr++;
                check[i]=1;
                prev=v[i];
                cnt++;
            }
            i++;
        }
        res++;        
    }
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