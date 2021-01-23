#include<iostream>
#include<vector>
#include<string>
using namespace std;

void combine(vector<int> &A, int s, int m, int e)
{
    int ptr1=s, ptr2=m+1, cnt=0;
    vector<int> temp(e-s+1);
    while(ptr1<=m && ptr2<=e)
    {
        if(to_string(A[ptr1])+to_string(A[ptr2])>to_string(A[ptr2])+to_string(A[ptr1]))
            temp[cnt++]=A[ptr1++];
        else
            temp[cnt++]=A[ptr2++];
    }
    while(ptr1<=m)
        temp[cnt++]=A[ptr1++];
    while(ptr2<=e)
        temp[cnt++]=A[ptr2++];
    cnt=0;
    for(int i=s;i<=e;i++)
        A[i]=temp[cnt++];
}

void DandC(vector<int> &A, int s, int e)
{
    if(s>e || s==e)
        return;
    int m = (s+e)/2;
    DandC(A,s,m);
    DandC(A,m+1,e);
    combine(A,s,m,e);
}

void print(vector<int> &a)
{
    for(auto i:a)
        cout<<i<<" ";
    cout<<endl;
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    DandC(a,0,a.size()-1);
    print(a);
    return 0;
}

bool compare(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1+s2>s2+s1;
}

string largestNumber(const vector<int> &A) {
    int cnt=0;
    string ans="";
    for(auto i:A)
    {
        if(i==0)
            cnt++;
    }
    if(cnt==A.size())
    {
        ans="0";
        return ans;
    }
    // Sorting const vector using a vector pointer!
    vector<int> *ptr = (vector<int>*)&A;
    sort(ptr->begin(), ptr->end(), compare);
    for(auto i:A)
        ans+=to_string(i);
    return ans;
}