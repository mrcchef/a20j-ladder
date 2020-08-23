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

// this is through two pointer technique

// 2

// 10100100010000

// First, let's calculate prefix sums of 1's. We get the following values:

// sum array =11222333344444

// Our C table looks like this: (C=cnt)

// C[0] = 1 // C[i] total number of 

// C[1] = 2

// C[2] = 3

// C[3] = 4

// C[4] = 5

// Now we iterate over C table starting from i = 2 (which is our k) to 4 (which is maximum sum of 1's).
//  Value C[i] is the count of positions which can be right end of our substring.
//  Now we need to find the number of positions which can be left end of the substring. 
//  Number of such positions is C[i — k]. For example for i = 3 we get the following possible left and right end positions:

// 1 0 1 0 0 1 0 0 0 1 0 0 0 0

// So for any i we've got C[i — k] (left ends) * C[i] (right ends) possible substrings with k 1's. Answer is the sum of such values for all i.

// Special case is k = 0. If I have for example C[2] = 3 it means that I have one position with 1 and two positions with 0s. So what I need to do now is to count number of all substrings of these two 0's. If Let's say I have n 0s, then I will have:

// n substrings of length 1 n — 1 substrings of length 2 n — 2 substrings of length 3 ... 1 substring of length n

// so generally the number of substrings of string of length n is sum of numbers from 1 to n which is n*(n+1)/2.

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
    ll k;
    string s;
    cin>>k;
    cin>>s;
    ll ans=0,i=0,n=s.size();
    ll sm[n+1]={0},cnt[n+1]={0},mx=INT_MIN;
    cnt[0]=1;
    fo(i,n)
    {   
        if(i==0)
        {
            sm[0]=s[i]-'0';
            cnt[sm[i]]++;
            mx=max(sm[i],mx);
            continue;
        }
        sm[i]=sm[i-1]+s[i]-'0';
        mx=max(sm[i],mx);
        cnt[sm[i]]++;
    }
    // fo(i,n)
    //     cout<<sm[i]<<" ";
    // cout<<endl;
    // fo(i,mx+1)
    //     cout<<cnt[i]<<" ";
    // cout<<endl;
    if(sm[n-1]<k)
    {
        cout<<0;
        return 0;
    }
    Fo(i,k,n+1)
    {
        if(k==0)
        {
            ans+=((cnt[i])*(cnt[i]-1))/2;
        }
        else
        {
            ans+=cnt[i]*cnt[i-k];
        }
    }
    cout<<ans<<endl;
        
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