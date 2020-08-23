#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
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

ll dpp[10001];

int cal(ll n,ll a,ll b,ll c)
{
    if(n<0)
        return -1;
    if(n==0)
        return 0;
    ll op1,op2,op3;
    if(dpp[n]!=0)
        return dpp[n];
    op1=cal(n-a,a,b,c);
    op2=cal(n-b,a,b,c);
    op3=cal(n-c,a,b,c);
    if(op1==-1 && op2==-1 && op3== -1)
        dpp[n]=-1;
    else
    {
        dpp[n]=max(max(op1,op2),op3)+1;    
    }

    return dpp[n];

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b,c;
        cin>>n>>a>>b>>c;
        ll dp[n+1]={0};
        ll op1,op2,op3;
        for(ll i=1;i<=n;i++)
        {
            op1=op2=op3=-1;
            if(i-a>=0)
                op1=dp[i-a];
            if(i-b>=0)
                op2=dp[i-b];
            if(i-c>=0)
                op3=dp[i-c];
            if(op1==-1 && op2==-1 && op3==-1)
                dp[i]=-1;
            else
            {
                dp[i]=max(max(op1,op2),op3)+1;
            }
        }
        ll res=cal(n,a,b,c);
        for(ll i=0;i<=n;i++)
            cout<<dp[i]<<" "<<dpp[i]<<endl;
        cout<<dp[n]<<" "<<dpp[n]<<endl;
    }
 return 0;
}
