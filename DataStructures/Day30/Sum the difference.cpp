#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A) {
    sort(A.begin(), A.end());
    unsigned int mod = 1000000007;
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int pos = j-i-1, cnt=1;
            while(pos)
            {
                cnt=((cnt<<1))%mod;
                pos--;
            }
            for(int k=0;k<(A[j]-A[i]);k++)
                ans = (ans+cnt)%mod;
        }
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
    cout<<solve(a)<<endl;
    return 0;
}