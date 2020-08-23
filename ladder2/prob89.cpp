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

// the only tricky thing in this question is about 0 2 2 case after taking modulos by 3
// b/c in this case actually if we does not make a bouquet of particular colour where 0 is remaning then 
// there would be 3 2 2 and now actually we can create 2 bouquet of mixed type i.e one more as compared to previous case.

int main()
{
    ll flag=0;
    ll a[3];
    for(ll i=0;i<3;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            flag=1;
    }
        
    ll sum=0;
    for(ll i=0;i<3;i++)
    {
        sum+=a[i]/3;
        a[i]=a[i]%3;
    }
    sort(a,a+3);
    if(a[0]==0 && a[1]==2 && a[2]==2)
    {
        if(flag==0)
            sum++;
    }
    sum+=a[0];
    cout<<sum;
    
 return 0;
}
