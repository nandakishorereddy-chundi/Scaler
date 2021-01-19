#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &A) {
    unsigned int pos=1, ans=0, sum;
    for(int i=0;i<32;i++)
    {
        sum=0;
        for(int j=0;j<A.size();j++)
            if(A[j]&pos)
                sum++;
        if(sum%3)
            ans|=pos;
        pos<<=1;
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
    cout<<singleNumber(a)<<endl;
    return 0;
}