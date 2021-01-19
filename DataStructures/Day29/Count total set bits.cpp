#include<iostream>
#include<vector>
using namespace std;

int solve(int A) {
    unsigned int mod = 1000000007;
    A++;
    int ans = 0;
    int pos=2;
    while(A/pos!=0 || A%pos-(pos>>1)>0)
    {
        ans=(ans+(A/pos)*(pos>>1))%mod;
        if(A%pos-(pos>>1)>0)
            ans+=A%pos-(pos>>1);
        pos<<=1;
    }
    return ans%mod;
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}