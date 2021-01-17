#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
    int start=0, end=1;
    while(start<A.size()-1)
    {
        if(A[end]-A[start]==B)
            return 1;
        else if(A[end]-A[start]<B)
            end++;
        else
        {
            start++;
            end=start+1;
        }
    }
    return 0;
}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(a, k)<<endl;
    return 0;
}