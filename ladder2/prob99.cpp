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

// First look at the table:

// X | Y | X^Y | X|Y
// 0 | 0 |  0  |  0
// 0 | 1 |  1  |  1
// 1 | 0 |  1  |  1
// 1 | 1 |  0  |  1
// This is the table with the operations and results. As we can see, when we try to convert to adjacent zeros, 
// we receive two zeroes again (00 -> 00). Similarly, when one of the adjacent digits is 1, 
// we receive atleast one 1 (10 -> 11, 01 -> 11, 11 -> 01 or 10). That means that we cannot receive two zeroes from 01, 10, and 11.

// That's why when one of the string is consisted only with zeros and the other has at least one 1, the transformation is impossible.

// The other conclusions are the following: 01 -> 11 -> 10 (1 is moved to the left) and 10 -> 11 -> 01 (1 is moved to the right).
//  These transformations allow us to move ones whenever we want. 01 -> 11, 10 -> 11, 11 -> 01 or 10.
//   The last transformations allow us to increase or decrease the number of ones as we like.

// // That means that we can reach any positive number of ones and we can arrange them whatever we like. 
// So when the two strings have at least one 1 each, then the transformation is possible.

// Of course, when the two string are consisted only with zeros, then there is no transformation needed, so the answer is YES.


int main()
{
    string a,b;
    cin>>a>>b;
    ll flag1=0,flag2=0;
    if(a.size()!=b.size())
    {
        cout<<"NO";
        return 0;
    }
    ll i=0,lt;
    for(ll i=0;i<b.size();i++)
    {
        if(b[i]=='1')
            flag1=1;
    }
    for(ll i=0;i<a.size();i++)
    {
        if(a[i]=='1')
            flag2=1;
    }
    if((flag1==0 && flag2==0)||(flag1==1 && flag2==1))
    {
        cout<<"YES";
    }
    else
        cout<<"NO";
     return 0;
}
