#include<iostream>
#include<vector>
using namespace std;

int get_pivot(const vector<int> &A, int s, int e)
{
    //cout<<"s = "<<s<<" "<<"e = "<<e<<endl;
    if(s==e)
        return s;
    int m=(s+e)/2;
    if(A[m]<A[0])
        return get_pivot(A,s,m-1);
    else
        return get_pivot(A,m+1,e);
}

int BinarySearch(const vector<int> &A, int s, int e, int B)
{
    if(s>e)
        return -1;
    int m=(s+e)/2;
    if(A[m]<B)
        return BinarySearch(A,m+1,e,B);
    else if(A[m]==B)
        return m;
    else
        return BinarySearch(A,s,m-1,B);
}

int search(const vector<int> &A, int B) {
    int pivot, ans=-1;
    pivot=get_pivot(A,0,A.size()-1);
    if(B>=A[0] && B<=A[pivot-1])
        return BinarySearch(A,0,pivot-1,B);
    else
        return BinarySearch(A,pivot,A.size()-1,B);
}

int QuickBinarySearch(const vector<int> &A, int s, int e, int B)
{
    if(s==e)
    {
        if(A[s]==B)
            return s;
        else
            return -1;
    }
    if(s>e)
        return -1;
    if(A[s]<A[e])
    {
        if(B>=A[s] && B<=A[e])
        {
            int m=(s+e)/2;
            if(B==A[m])
                return m;
            else if(B<A[m])
                return QuickBinarySearch(A,s,m-1,B);
            else
                return QuickBinarySearch(A,m+1,e,B);
        }
        else
            return -1;
    }
    else
    {
        int m=(s+e)/2;
        int lpart = QuickBinarySearch(A,s,m,B);
        int rpart = QuickBinarySearch(A,m+1,e,B);
        if(lpart==-1 && rpart==-1)
            return -1;
        if(lpart!=-1)
            return lpart;
        else
            return rpart;
        
    }
}

int main()
{
    int n, b;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>b;
    cout<<search(a, b)<<endl;
    return 0;
}