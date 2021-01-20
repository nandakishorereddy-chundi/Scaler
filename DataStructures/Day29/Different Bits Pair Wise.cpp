#include<iostream>
#include<vector>
using namespace std;

int cntBits(vector<int> &A) {
    int pos=1, ones[32]={}, zeros[32]={}, ans=0;
    unsigned int mod = 1000000007;
    for(int j=0;j<32;j++)
    {
        for(auto i:A)
        {
            if(i&pos)
                ones[j]++;
            else
                zeros[j]++;
        }
        pos<<=1;
    }
    for(int i=0;i<32;i++)
    {
        ans=(ans+((ones[i]*zeros[i])%mod+(ones[i]*zeros[i])%mod)%mod+mod)%mod;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<cntBits(a)<<endl;
    return 0;
}