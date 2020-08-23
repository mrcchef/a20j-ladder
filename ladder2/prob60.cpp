#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include<bits/stdc++.h> 
using namespace std;
#define ll int
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
    string s1,s2;
    cin>>s1>>s2;
    ll v1=0,v2=0,q=0;
    for(ll i=0;i<s1.size();i++)
        if(s1[i]=='+')
            v1++;
        else
            v1--;
    for(ll i=0;i<s2.size();i++)
        if(s2[i]=='+')
            v2++;
        else if(s2[i]=='-')
            v2--;
        else 
            q++;
    float res=0,cnt=0;
    if(q==0)
    {
        if(v1==v2)
        {
            res=1.0;
        }
        else
        {
            res=0.0;
        }
        cout<<res<<endl;
    }
    else
    {
        for(ll i=1;i<=(1<<q);i++)
        {
            ll j=q,val=0,n=i;
            while(j>0)
            {
                if(n&1)
                {
                    val++;
                }
                else
                {
                    val--;
                }
                j--;
                n=n>>1;
            }
            if(val+v2==v1)
            {
                cnt++;
            }
        }
        res=cnt/(1<<q);
        cout<<setprecision(12)<<res<<endl;
    }

    return 0;
}
