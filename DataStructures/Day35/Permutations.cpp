#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >ans;

void print(vector<int> &temp)
{
    for(auto i:temp)
        cout<<i<<" ";
    cout<<endl;
}

void recur_func(int index, vector<int> &A)
{
    if(index == A.size()-1)
    {
        ans.push_back(A);
        return;
    }
    for(int i=index;i<A.size();i++)
    {
        swap(A[index], A[i]);
        recur_func(index+1, A);
        swap(A[index], A[i]);
    }
}

vector<vector<int> > permute(vector<int> &A) {
    ans.clear();
    recur_func(0, A);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    permute(a);
    for(auto i:ans)
        print(i);
    return 0;
}