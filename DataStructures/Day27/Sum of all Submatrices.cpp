#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int> > &A)
{
    int n, sum=0;
    n=A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            sum+=A[i][j]*(i+1)*(j+1)*(n-i)*(n-j);
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > a(n);
    for(int i=0;i<n;i++)
    {
        a[i]=vector<int>(n);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    cout<<solve(a)<<endl;
    return 0;
}