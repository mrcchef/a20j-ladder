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
    
        string s,n;
        cin>>s;
        ll i=0;
        while(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
        {
            s.erase(s.begin(),s.begin()+3);
        }
        ll index=s.find("WUB");
        while(index<s.size()) //we can also use string::npos 
        {
            s.insert(index," ");
            s.erase(s.begin()+index+1,s.begin()+index+4);
            index=s.find("WUB");
        }
        cout<<s;

}
