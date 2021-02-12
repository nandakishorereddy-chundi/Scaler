#include<iostream>
#include<vector>
using namespace std;

int peak(vector<int> &A, int s, int e)
{
    //cout<<"s = "<<s<<" "<<"e = "<<e<<endl;
    int m=(s+e)/2;
    if(m>0 && m<A.size()-1 && A[m]>A[m-1] && A[m]>A[m+1])
        return A[m];
    if(m==0 || m==A.size()-1)
    {
        if(m==0)
            return max(A[0], A[1]);
        else if(m==A.size()-1)
            return max(A[m], A[m-1]);
    }
    if(A[m]<A[m-1])
        return peak(A,s,m-1);
    else
        return peak(A,m+1,e);
}

int solve(vector<int> &A) {
    if(A.size()==1)
        return A[0];
    return peak(A, 0, A.size()-1);
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