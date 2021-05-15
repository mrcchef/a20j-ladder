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

ll R,C;
char arr[110][110];

void solve(ll i,ll j)
{
    if(i<0 || j<0 || i>=R || j>=C)
        return;
    
    if(arr[i][j]=='-')
        return ;

    if((i+1<R && arr[i+1][j]=='B') || (i-1>=0 && arr[i-1][j]=='B') || (j-1>=0 && arr[i][j-1]=='B') || (j+1<C && arr[i][j+1]=='B'))
        arr[i][j]='W';
    else
        arr[i][j]='B';
    for(ll k=0;k<4;k++)
    {
        solve(i+dx[k],j+dy[k]);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll i,j;
        cin>>R>>C;
        fo(i,R)
        {
            fo(j,C)
                cin>>arr[i][j];
        }

        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                cout<<arr[i][j];
            cout<<endl;
        }

        solve(0,0);

        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                cout<<arr[i][j];
            cout<<endl;
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