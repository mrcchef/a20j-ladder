#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
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

//https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/
//Article for next permutation function

int main()
{
        ll a[5][5];
        for(ll i=0;i<5;i++)
            for(ll j=0;j<5;j++)
                cin>>a[i][j];
        ll p[5];
        for(ll i=0;i<5;i++)
            p[i]=i;
        ll res=0,ans=0;
        do
        {
            res=a[p[0]][p[1]]+a[p[1]][p[0]];
            res+=a[p[2]][p[3]]+a[p[3]][p[2]];
            res+=a[p[1]][p[2]]+a[p[2]][p[1]];
            res+=a[p[3]][p[4]]+a[p[4]][p[3]];
            res+=a[p[2]][p[3]]+a[p[3]][p[2]];
            res+=a[p[3]][p[4]]+a[p[4]][p[3]];
            if(res>ans)
            {
                ans=res;
            }
        }while(next_permutation(p, p+5));
        
        cout<<ans<<endl;
    
   
 return 0;
}
