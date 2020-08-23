#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb puah_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
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
// LOgic
// here we are traking the current hight and current width
// ch represent the height of last column where box is placed
// cw represents the maxmium width till a particular test case or the maximum width till now
// if cw<w it means the box can go beyond the cw 
// and it could be placed at highest height of original array or the last height which is height after the last box is placed
// and then we update the cw and print it and also update it after placing the box and also update the new height
// else width is less that is we can not go to the next column and can not go below b/c cw is larger and object can not go below it 
// and that is why that box will be placed at ch 
// and we will update the height and no need to update cw b/c it is already greator  
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    ll m;
    cin>>m;
    ll ch=0,cw=0;
    while(m--)
    {
        ll h,w;
        cin>>w>>h;
        if(cw<w)
        {
            ch=max(ch,a[w-1]);
            cout<<ch<<endl;
            ch+=h;
            cw=w;
        }
        else
        {
            cout<<ch<<endl;
            ch+=h;
        }
    }
 return 0;
}
