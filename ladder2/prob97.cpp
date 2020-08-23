#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
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
#define deb(x) cout << #x << "=" << x << endl
const double mod = 1e9+7;

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

bool cmp(pair<ll, ll>& a, 
         pair<ll, ll>& b) 
{ 
    return a.second > b.second; 
} 
  
// Function to sort the map according 
// to value in a (key-value) pairs 
vector<pair<ll,ll>> sort_m(map<ll, ll>& M) 
{ 
  
    // Declare vector of pairs 
    vector<pair<ll, ll> > A; 
  
    // Copy key-value pair from Map 
    // to vector of pairs 
    for (auto& it : M) { 
        A.push_back(it); 
    } 
  
    // Sort using comparator function 
    sort(A.begin(), A.end(), cmp); 
    return A;
} 

int main()
{
    ll n,q,i;
    cin>>n>>q;
    ll a[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    map<ll,ll> M;
    vector<pair<ll,ll>> vp;
    fo(i,q)
    {
        ll st,ed;
        cin>>st>>ed;
        vp.pb({st,ed});
        M[st]++;
        M[ed]++;
    }
    vector<pair<ll,ll>> m=sort_m(M);
    ll res[n+1]={0};
    sort(a,a+n,greater<ll>());
    i=1;
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<"->"<<it->second<<endl;
        res[it->first]=a[i++];
    }
    for(ll j=1;j<=n;j++)
    {
        if(res[j]==0)
            res[j]=a[i++];
    }
    for(ll j=1;j<=n;j++)
        cout<<res[j]<<" ";
    cout<<endl;
    ll sm[n+1]={0};
    sm[1]=res[1];
    deb(sm[1]);
    for(i=2;i<=n;i++)
    {
        sm[i]=sm[i-1]+res[i];
        deb(sm[i]);
    }
    ll ans=0;
    for(ll j=0;j<=n;j++)
        cout<<sm[j]<<" ";
    cout<<endl;        
    for(auto it=vp.begin();it!=vp.end();it++)
    {   
        ll st=it->first;
        ll ed=it->second;
        cout<<st<<" "<<ed<<endl;
        ans+=sm[ed]-sm[st-1];
        deb(ans);
    }
    cout<<ans<<endl;
 return 0;
}
