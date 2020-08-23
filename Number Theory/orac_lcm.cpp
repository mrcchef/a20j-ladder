#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll int
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

// Good Problem
//https://www.youtube.com/watch?v=9EUSdYj7aqs&list=PL2q4fbVm1Ik7Fz2JrP7meOtxUvEXy926-&index=3

ll power(ll a , ll n)
{
	ll res = 1;
	
	while(n)
	{
		if(n & 1)
		res = (res * a);
		
		n >>= 1;
		a = (a * a);
	}
	
	return res;
}
 

bool check[20005];
vi primes;


void sieve()
{
    ll max=20005;
    for(ll i=0;i<max;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(ll i=2;i<max;i++)
    {
        if(check[i])
        {  
            primes.pb(i);
            for(ll j=i*i;j<max;j+=i)
            {
                check[j]=false;
            } 
        }
    }    
}

// vi PFactor(ll n)
// {
//     vi v;
//     for(ll i=2;i*i<=n;i++)
//     {
//         if(n%i==0)
//         {
//             v.pb(i);
//             while(n%i==0)
//             {
//                 n=n/i;
//             }
//         }
//     }
//     if(n>1)
//         v.pb(n);
//     return v;
// }


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,j,ans=1;
    cin>>n;
    vi v;
    fo(j,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    sieve();
    map<int,vector<int>> mv;
    fo(j,n)
    {
        ll val=v[j];
        for(ll i=2;i*i<=val;i++)
        {
            ll cnt=0;
            if(val%i==0)
            {
                while(val%i==0)
                {
                    val=val/i;
                    cnt++;
                }
                mv[i].pb(cnt);
            }
            if(val>1)
            {
                mv[val].pb(1);
            }
        }
    }
    for(auto x:primes)
    {
        if(mv.find(x)==mv.end() || mv[x].size()<=n-2)
            continue;
        sort(mv[x].begin(),mv[x].end());
        if(mv[x].size()==n-1)
        {
            ans*=power(x,mv[x][0]);
        }
        else
        {
            ans*=power(x,mv[x][1]);
        }
    
    }

    // for(auto it=mv.begin();it!=mv.end();it++)
    // {
    //     sort(it->second.begin(),it->second.end());
    //     if((it->second).size()<=n-2)
    //     {
    //         continue;
    //     }
    //     if((it->second).size()==n-1)
    //     {
    //         vi v=it->second;
    //         ans*=fxp(it->first,v[0],mod);
    //     }
    //     else
    //     {
    //         vi v=it->second;
    //         ans*=fxp(it->first,v[1],mod);
    //     }
        
    // }
    cout<<ans;
    

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