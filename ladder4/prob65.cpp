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

// Question is simple we just need to check the MSB's of both the numbers i.e. we have to count the length of the continous array 
// having same bit from right and then we have to subtract than number to the length of the bigger number and simply calcuate the
// a number with all 1's with length = original length - length of continous array

bool isset(ll n,ll i)
{
    ll mask=(ll)1<<i;
    ll val=n & mask;
    // deb(val);
    if(val!=0)
        return true;
    return false;
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
        ll l,r;
        cin>>l>>r;
        if(l==r)
        {
            cout<<0<<endl;
            return 0;
        }
        ll ln=log2(r)+1;
        
        ll cnt=0,i=ln-1;
        // deb(ln);
        while(i>=0)
        {
            bool check1,check2;
            check1=isset(l,i);
            check2=isset(r,i);
            // deb(check1);
            // deb(check2);
            if((check1 and check2) || (!check1 and !check2))
            {
                cnt++;
                i--;
            }
            else
                break;
            
        }

        ll V=(ll)1<<(i+1);
        V--;
        cout<<V<<endl;
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