#include<iostream>
#include<vector>
using namespace std;

int ans=0;
unsigned int mod = 1000000007;
void count_inversions(vector<int> &A, int s, int m, int e)
{
    int ptr1=s, ptr2=m+1, cnt=0;
    vector<int> temp(e-s+1, 0);
    while(ptr1<=m && ptr2<=e)
    {
        if(A[ptr1]>A[ptr2])
            temp[cnt++]=A[ptr2++];
        else
            temp[cnt++]=A[ptr1++];
    }
    while(ptr1<=m)
        temp[cnt++]=A[ptr1++];
    while(ptr2<=e)
        temp[cnt++]=A[ptr2++];
    ptr1=s;
    ptr2=m+1;
    while(ptr1<=m && ptr2<=e)
    {
        if(A[ptr1]>A[ptr2])
        {
            ans=(ans+(m-ptr1+1))%mod;;
            ptr2++;
        }
        else
            ptr1++;
    }
    int j=0;
    for(int i=s;i<=e;i++)
        A[i]=temp[j++];
}

void DandC(vector<int>&A, int s, int e)
{
    if(s>=e)
        return;
    int m=(s+e)/2;
    DandC(A,s,m);
    DandC(A,m+1,e);
    count_inversions(A,s,m,e);
}

int solve(vector<int> &A) {
    DandC(A,0,A.size()-1);
    int _count;
    _count=ans;
    ans=0;
    return _count;
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