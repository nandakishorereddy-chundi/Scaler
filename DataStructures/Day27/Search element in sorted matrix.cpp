#include "../stdc++.h"
using namespace std;

int solve(vector<vector<int> >&A, int B)
{
    int rows, cols, k=0, ans = INT_MAX;
    rows = A.size();
    cols = A[0].size();
    for(int i=0;i<rows;i++)
    {
        int index = lower_bound(A[i].begin(), A[i].end(), B)-A[i].begin();
        if(A[i][index]==B)
            ans = min(ans, ((i+1)*1009)+index+1);
    }
    if(ans == INT_MAX)
        return -1;
    else
        return ans;
}

int main()
{
    int n,m,b;
    cin>>n>>m>>b;
    vector<vector<int> > a(n);
    for(int i=0;i<n;i++)
    {
        a[i]=vector<int>(m);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    cout<<solve(a, b)<<endl;
    return 0;
}