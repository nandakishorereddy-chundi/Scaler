#include<iostream>
#include<vector>
using namespace std;

unsigned int reverse(unsigned int A) {
    vector<int> a(32);
    unsigned int b=1;
    for(int i=31;i>=0;i--)
    {
        if(A&b)
            a[i]=1;
        b=b<<1;
    }
    unsigned int ans=0, pro=1;
    for(int i=0;i<32;i++)
    {
        ans+=(pro*a[i]);
        pro=pro<<1;
    }
    return ans;
}

int main()
{
    unsigned int n;
    cin>>n;
    cout<<reverse(n)<<endl;
    return 0;
}