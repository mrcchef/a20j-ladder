#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
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
#define deb(x) cout << #x << "=" << x << endl
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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll g1=__gcd(a,b);
    ll g2=__gcd(c,d);
    a=a/g1;
    b=b/g1;
    c=c/g2;
    d=d/g2;
    ll cn,cd,dn,dd,total=a*b,m_an,m_ad,res_n,res_d;
    if(c>d)
    {
        cn=a;
        cd=1;
        dn=d*a;
        dd=c;
        ll g=__gcd(dn,dd);
        dn=dn/g;
        dd=dd/g;
    }
    else
    {
        dn=b;
        dd=1;
        cn=c*b;
        cd=d;
        ll g=__gcd(cn,cd);
        cn=cn/g;
        cd=cd/g;
    }
    res_n=cd*dd*a*b-cn*dn;
    res_d=cd*dd*a*b;
    if(res_n<0)
    {
        res_n=abs(res_n);
        res_d=res_d+res_n;
    }
    ll g=__gcd(res_n,res_d);
    res_n=res_n/g;
    res_d=res_d/g;
    cout<<res_n<<"/"<<res_d<<endl;
 return 0;
}
