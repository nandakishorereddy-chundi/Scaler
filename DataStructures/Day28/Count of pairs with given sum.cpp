#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
    int start, end, cnt;
    start=0;
    end=A.size()-1;
    cnt=0;
    while(start<end)
    {
        if(A[start]+A[end]==B)
        {
            cnt++;
            start++;
            end--;
        }
        else if(A[start]+A[end]<B)
            start++;
        else
            end--;
    }
    return cnt;
}

int main()
{
    int n,b;
    cin>>n>>b;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(a, b)<<endl;
    return 0;
}