#include <iostream>
// THis question can be solved using kadane's algorithm
// This algo is used to cal. largest sum of contigious subarray
// this problem is similar to cal largest sum or maximum no. of 1s in a subarray
using namespace std;

int main()
{
    int n, a, count1(0), extra0(0), extra0max(-1);
    cin >> n;
    // solution of this problem is basically all the 1s and the maximum no. of 0s which actually flips to become 1.
    while (n--)
    {
        cin >> a;
        if (a == 1)
        {
            count1 += 1;
            if (extra0 > 0)// if we get 1 after any zero that means that zero is useless for uss
            {
                extra0 -= 1;
            }
        }
        else
        {
            extra0 += 1;
            if (extra0 > extra0max) 
            {
                extra0max = extra0; // it stores the maximum no. of zeroes which does not cancel the effect of 1
            }
        }
    }
    cout << count1 + extra0max << endl;
    return 0;
}