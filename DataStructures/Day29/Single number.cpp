#include<iostream>
#include<vector>
using namespace std;

int singleNumber(const vector<int> &A) {
    int ans=0;
    for(auto i: A)
        ans^=i;
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