#include<iostream>
#include<vector>
using namespace std;

double avg(int a, int b)
{
    return (a+b)/2.0;
}

double func(const vector<int>&A, const vector<int> &B, int s, int e)
{
    int px,py,maxL,minL,maxR,minR;
    px=(s+e)/2;
    py=((A.size()+B.size()+1)/2)-px;
    minL = (px==0)? INT_MIN : A[px-1];
    maxL = (px==A.size()) ? INT_MAX : A[px];
    minR = (py==0)? INT_MIN : B[py-1];
    maxR = (py==B.size()) ? INT_MAX : B[py];
    //cout<<minL<<" "<<maxL<<" "<<minR<<" "<<maxR<<endl;
    if(minL<=maxR && minR<=maxL)
    {
        if((A.size()+B.size())%2)
            return max(minL, minR)/1.0;
        else
            return avg(max(minL, minR), min(maxL, maxR));
    }
    else if(minL>maxR)
        return func(A,B,s,px-1);
    else
        return func(A,B,px+1,e);
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if(A.size()<B.size())
        return func(A,B,0,A.size());
    else
        return func(B,A,0,B.size());
}

int main()
{
    int n,m;
    double ans;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    cout<<findMedianSortedArrays(a,b)<<endl;
    return 0;
}