#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ; cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<=n;i++)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<":"<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<" : "<<f<<endl
const ll mod = 1e9+7;
#define popcount(x) __builtin_popcount(x)
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof(a))
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

void solve()
{
    ll n,k,p,i;
    cin>>n>>k>>p;
    vi v(n);
    vi odd,even;
    vector<vi> ans;
    fo(i,n)
    {
        cin>>v[i];
        if(v[i]&1)
            odd.pb(v[i]);
        else
            even.pb(v[i]);
    }
    
    ll cnt=0;

    if(even.size()<p)
    {
        ll rem=p-even.size();
        trace4(even.size(),odd.size(),rem,1);
        if(odd.size()-2*rem<0)
        {
            cout<<"NO";
            return;
        }
        ll cntp=0;
        while(!even.empty())
        {
            vi temp;
            temp.pb(even.back());
            ans.pb(temp);

            even.pop_back();
            cntp++;
        }

        ll cnto=0;
        while(cnto<rem)
        {
            vi temp;
            temp.pb(odd.back());
            odd.pop_back();
            temp.pb(odd.back());
            odd.pop_back();
            ans.pb(temp);
            cnto++;
        }



        if(odd.size()<k-p-cnto || (odd.size()-(k-p)-cnto)%2==0)
        {
            cout<<"NO";
            return;
        }

        ll cnto1=0;
        while(cnto1+1<k-p-cnto)
        {
            vi temp;
            temp.pb(odd.back());
            odd.pop_back();
            ans.pb(temp);
            cnto1++;
        }

        vi temp;
        while(!odd.empty())
        {
            temp.pb(odd.back());
            odd.pop_back();
        }
        if(!temp.empty())
            ans.pb(temp);
    }
    else if(even.size()>p)
    {
        ll rem=even.size()-p;
        // trace3(even.size(),odd.size(),2);
        if(odd.size()<k-p)
        {
            cout<<"NO";
            return;
        }

        ll cntp=0;
        while(cntp<p)
        {
            vi temp;
            temp.pb(even.back());
            ans.pb(temp);

            even.pop_back();
            cntp++;
        }

        ll cnto=0;
        while(cnto+2<k-p)
        {
            vi temp;
            temp.pb(odd.back());
            ans.pb(temp);
            odd.pop_back();
            cnto++;
        }

        if(odd.size()%2==0)
        {
            vi temp1;
            temp1.pb(odd.back());
            odd.pop_back();
            ans.pb(temp1);

            vi temp;
            while(!odd.empty())
            {
                temp.pb(odd.back());
                odd.pop_back();
            }
            while(!even.empty())
            {
                temp.pb(even.back());
                even.pop_back();
            }
            ans.pb(temp);
        }
        else
        {
            cout<<"NO";
            return;
        }

        // vi temp;
        // while(!odd.empty())
        // {
        //     temp.pb(odd.back());
        //     odd.pop_back();
        // }

        // while(!even.empty())
        // {
        //     temp.pb(even.back());
        //     even.pop_back();
        // }

        // ans.pb(temp);
    }
    else
    {
        ll cntp=0;
        while(cntp<p)
        {
            vi temp;
            temp.pb(even.back());
            even.pop_back();
            ans.pb(temp);
            // cout<<"1 "<<even.back()<<endl;
            // even.pop_back();
            cntp++;
        }
        // Need to take care about odd

        ll diff=odd.size()-(k-p);
        // trace4(even.size(),odd.size(),diff,3);
        if(odd.size()<k-p)
        {
            cout<<"NO";
            return;
        }

        ll cnto=0;
        if(k-p==1)
        {
            vi temp;
            temp.pb(odd.back());
            ans.pb(temp);
            odd.pop_back();
        }
        else
        {
            while(cnto+2<k-p)
            {
                vi temp;
                temp.pb(odd.back());
                ans.pb(temp);
                odd.pop_back();
                cnto++;
            }

            if(odd.size()%2==0)
            {
                vi temp1;
                temp1.pb(odd.back());
                odd.pop_back();
                ans.pb(temp1);

                vi temp;
                while(!odd.empty())
                {
                    temp.pb(odd.back());
                    odd.pop_back();
                }
                ans.pb(temp);
            }
            else
            {
                cout<<"NO";
                return;
            }

        }
        

    }

    cout<<"YES"<<endl;
    for(auto vec:ans)
    {
        cout<<vec.size()<<" ";
        for(auto val:vec)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    
    }
}

int main()
{
    fastio
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();   
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