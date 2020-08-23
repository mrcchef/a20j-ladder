#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long int
#define mod 1e9+7

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
    
        string s;
        cin>>s;
        auto it=s.begin();
        while(it!=s.end())
        {
            ll flag=0;
            if(*it<=90 && *it >=65)
                *it+=32;
            if(*it=='a'||*it=='e'||*it=='i'||*it=='o'||*it=='u')
            {
                s.erase(it);         // Here I used flag b/c if we erase things from string then the iterator automatically points to next character
                flag=1;               // For that iterator should not increase b/c if increases, it increase by 2
            }
            else
            {
                s.insert(it,'.');
                it++;
            }
            if(flag!=1)
                it++;
        }
        cout<<s;
    
 return 0;
}