#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int ptr1=0, ptr2=0, ptr3=0, ans=INT_MAX;
    while(ptr1<A.size() && ptr2<B.size() && ptr3<C.size())
    {
        ans = min(ans, abs(max(max(A[ptr1], B[ptr2]), C[ptr3])-min(min(A[ptr1], B[ptr2]), C[ptr3])));
        if(A[ptr1] <= B[ptr2] && A[ptr1]<= C[ptr3])
            ptr1++;
        else if(B[ptr2] <= A[ptr1] && B[ptr2]<= C[ptr3])
            ptr2++;
        else if(C[ptr3] <= A[ptr1] && C[ptr3]<= B[ptr2])
            ptr3++;
    }
    return ans;
}

int main()
{
    int l,m,n;
    cin>>l>>m>>n;
    vector<int> a(l), b(m), c(n);
    for(int i=0;i<l;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    cout<<solve(a,b,c)<<endl;
    return 0;
}