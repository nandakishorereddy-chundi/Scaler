#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &a)
{
    for(auto i:a)
        cout<<i<<" ";
    cout<<endl;
}

vector<int> searchRange(const vector<int> &A, int B) {
    vector<int> ans;
    int s=0, e=A.size()-1, m, fg=0, ptr1, ptr2;
    while(s<=e)
    {
        m=(s+e)/2;
        if(A[m]==B)
        {
            ptr1=ptr2=m;
            fg=1;
            while(ptr1>=0 && A[ptr1]==B)
                ptr1--;
            while(ptr2<=A.size()-1 && A[ptr2]==B)
                ptr2++;
            ans.push_back(++ptr1);
            ans.push_back(--ptr2);
            break;
        }
        else if(A[m]>B)
            e=m-1;
        else
            s=m+1;
    }
    if(fg==0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    return ans;
}

int main()
{
    int n, b;
    cin>>n;
    vector<int> a(n), ans;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>b;
    ans = searchRange(a, b);
    print(ans);
    return 0;
}