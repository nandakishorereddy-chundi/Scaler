#include<iostream>
#include<vector>
using namespace std;

vector<int> wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int ptr1=0, ptr2=1;
    for(;ptr1<=A.size()-2&&ptr2<=A.size()-1;ptr1+=2,ptr2+=2)
        swap(A[ptr1], A[ptr2]);
    return A;
}

void print(vector<int> &A)
{
    for(auto i:A)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n), ans;
    for(int i=0;i<n;i++)
        cin>>a[i];
    ans=wave(a);
    print(ans);
    return 0;
}