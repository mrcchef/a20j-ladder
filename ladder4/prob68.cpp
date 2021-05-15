#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,a,b) for(ll i=(a);i<=(b);++i)
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

ll dp[1005][2];

// "." charater = white 
// "#" character = black

//https://codeforces.com/blog/entry/59945
// Audio is also available



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll r,c,x,y,i,j;
        cin>>r>>c>>x>>y;
        char arr[r+1][c+1];
        Fo(i,1,r)
        {
            Fo(j,1,c)
            {
                cin>>arr[i][j];
            }
        }     
        
        ll white[c+1]={0};
        Fo(i,1,c)
        {
            Fo(j,1,r)
            {
                if(arr[j][i]=='.')
                    white[i]++;
            }
        }

        Fo(i,1,c)
        {
            dp[i][0]=dp[i][1]=LONG_LONG_MAX;
        }

        Fo(i,1,c)
        {
            ll sm=0;
            for(j=i;j>=max(1LL,i-y+1);j--)
            {
                sm+=white[j];
                if(i-j+1>=x && i-j+1<=y && dp[j-1][0]!=LONG_LONG_MAX)
                {
                    dp[i][1]=min(dp[i][1],sm+dp[j-1][0]);
                }
            }
            sm=0;
            for(j=i;j>=max(1LL,i-y+1);j--)
            {
                sm+=r-white[j];
                if(i-j+1>=x && i-j+1<=y && dp[j-1][0]!=LONG_LONG_MAX)
                {
                    dp[i][0]=min(dp[i][0],sm+dp[j-1][1]);
                }
            }
        }
        ll ans=min(dp[c][0],dp[c][1]);
        cout<<ans<<endl;

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