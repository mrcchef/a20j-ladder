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
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    // {
        ll n,x,i,res=0,mx=INT_MIN;
        cin>>n>>x;
        vi v;
        v.pb(0);
        fo(i,n)
        {
            ll temp;
            cin>>temp;
            mx=max(mx,temp);
            v.pb(temp); 
        }
        sort(v.begin(),v.end());
        bool check=binary_search(v.begin(),v.end(),x);
        ll pos;
        if(!check)
        {
            res=1;
            pos=upper_bound(v.begin(),v.end(),x)-v.begin();
            // deb(pos);
            v.insert(v.begin()+pos,x);
            n=n+1;
        }
        ll val=v[(n+1)/2];
            while(val!=x)
            {
                if(val>x)
                {
                    v.insert(v.begin(),1);
                }
                else
                {
                    v.pb(mx);
                }
                n++;
                val=v[(n+1)/2];
                res++;
            }    
        cout<<res<<endl;
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(a*a,b/2,m);
    return fxp(a,b-1,m)*a;
}
