#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > ans;

void print(vector<int> &temp)
{
    for(auto i:temp)
        cout<<i<<" ";
    cout<<endl;
}

void recur_func(int index, vector<int> &A, vector<int> &temp)
{
    ans.push_back(temp);
    //print(temp);
    for(int i=index;i<A.size();i++)
    {
        temp.push_back(A[i]);
        recur_func(i+1, A, temp);
        temp.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    ans.clear();
    vector<int> temp;
    recur_func(0, A, temp);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    subsets(a);
    for(auto i:ans)
        print(i);
    return 0;
}