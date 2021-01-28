#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
    int sum=0, sum1=0, sum2=0;
    for(auto i:A)
        sum+=i;
    sort(A.begin(), A.end());
    for(int i=0;i<B;i++)
        sum1+=A[i];
    for(int i=A.size()-1;i>A.size()-B-1;i--)
        sum2+=A[i];
    return max(abs((2*sum1)-sum), abs((2*sum2)-sum));
}

int main()
{
    int n,b;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>b;
    cout<<solve(a, b)<<endl;
    return 0;
}