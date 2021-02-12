#include<iostream>
#include<vector>
using namespace std;

#define ll long long
int ans=0;
bool isPossible(vector<int> &A, int m, int B)
{
    ll sum=0;
    int i=0, j=m;
    for(i=0;i<j;i++)
        sum+=A[i];
    if(sum>B)
        return 0;
    i=0;
    for(j=m;j<A.size();i++,j++)
    {
        sum-=A[i];
        sum+=A[j];
        if(sum>B)
            return 0;
    }
    return 1;
}

int func(vector<int> &A, int s, int e, int B)
{
    if(s==e)
    {
        if(isPossible(A,s,B))
            return s;
        else
            return ans;
    }
    if(s>e)
        return ans;
    int m=(s+e)/2;
    //cout<<"m = "<<m<<endl;
    if(isPossible(A,m,B))
    {
        //cout<<"true"<<endl;
        ans=m;
        return func(A,m+1,e,B);
    }
    else
    {
        //cout<<"false"<<endl;
        return func(A,s,m-1,B);
    }
}

int solve(vector<int> &A, int B) {
    return func(A, 0, A.size(), B);
}

int main()
{
    int n,S;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>S;
    cout<<solve(a,S)<<endl;
    return 0;
}