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
#define pb push_back
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

// Sum of digits (B Div-2)
// Initial number consist of no more then 100000 digits. Therefore after first transform resulting number will be no more then 900000, 
// and then it will constist of no more then 6 digits.
//  Thus after next transform number will be no more then 54 and so it will be two-digit or one-digit.
//  Sum of digits of a two-digit number no more, then 18, and sum of digit of such number no more, then 9.
// Thus Gerald can't do nore, then 4 transforms. 
// First transform one can implement one simple pass throw symbols of given string. Following operations take very little time.

int main()
{
    string s;
    cin>>s;
    ll cnt=1;
    ll sz=s.size();
    if(sz==1)       
        cout<<0<<endl;
    else
    {
        ll smd=0,temp;
        for(ll i=0;i<sz;i++)
        {
            smd+=s[i]-'0';
        }
        while(smd>9)
        {
            temp=smd;
            smd=0;
            while(temp>0)
            {
                smd+=temp%10;
                temp=temp/10;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
 return 0;
}
