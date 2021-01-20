#include<iostream>
#include<vector>
using namespace std;

int findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int XOR=INT_MAX;
    for(int i=0;i<A.size()-1;i++)
        XOR=min(XOR, A[i]^A[i+1]);
    return XOR;
}


int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<findMinXor(a)<<endl;
}