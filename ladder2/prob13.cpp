#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
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

int main()
{
    
        ll r,c;
        cin>>r>>c;
        char x;
        ll a[r][c];
        for(ll i=0;i<r;i++)
        {
            for(ll j=0;j<c;j++)
            {
                cin>>x;
                if(x=='.')
                    a[i][j]=1;
                else if(x=='S')
                    a[i][j]=-1;
            }
        }
        ll res=0;
        for(ll i=0;i<r;i++)
        {
            ll stmp=0;
            for(ll j=0;j<c;j++)
            {
                if(a[i][j]==-1)
                {
                    stmp=0;
                    break;
                }
                else if(a[i][j]==1)
                    stmp++;
            }
            if(stmp!=0)
                for(ll j=0;j<c;j++)
                    a[i][j]=0;
            res+=stmp;
        }
        // for(ll i=0;i<r;i++)
        // {  for(ll j=0;j<c;j++)
        //         cout<<a[i][j]<<" ";
        //     cout<<endl;
        // }

        for(ll i=0;i<c;i++)
        {
            ll stmp=0;
            for(ll j=0;j<r;j++)
            {
                if(a[j][i]==-1)
                {
                    stmp=0;
                    break;
                }
                else if(a[j][i]==1)
                    stmp++;
            }
            res+=stmp;
        }
        cout<<res<<endl;
    
 return 0;
}
