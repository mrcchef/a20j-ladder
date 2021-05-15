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
        ll n,i;
        cin>>n;
        vi v;
        mii m;
        fo(i,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        if(n==1)
        {
            cout<<-1;
            return 0;
        }
        set<ll> s;
        sort(v.begin(),v.end());
        for(i=1;i<n;i++)
        {
            ll diff=v[i]-v[i-1];
            // deb(diff);
            m[diff]++;
        }
        // for(auto x:m)
        //     cout<<x.first<<" "<<x.second<<endl;
        // deb(m.size());
        if(m.size()==1)
        {
            ll diff=m.begin()->first;
            s.insert(v[0]-diff);
            s.insert(v[v.size()-1]+diff);
            if(m.begin()->second==1)
            {
                if(diff%2==0)
                    s.insert(v[0]+diff/2);
            }
        }
        else if(m.size()==2)
        {
            auto it=m.begin();
            // deb(it->first);
            auto it1=m.begin();
            it1++;
            // deb(it1->first);
            if(it1->second==1)
            {
                // deb(it1->first);
                if((it1->first)%2==0 && (it1->first)/2==it->first)
                {
                    for(i=1;i<n;i++)
                        if(v[i]-v[i-1]==it1->first)
                        {
                            s.insert(v[i-1]+it->first);
                            break;
                        }    
                }
            }
        }
        
        cout<<s.size()<<endl;
        for(auto it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
        }

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