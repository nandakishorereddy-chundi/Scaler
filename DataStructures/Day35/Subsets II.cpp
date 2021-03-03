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

void recur_func(int index, vector<int> &A, vector<int> &temp)
{
    ans.push_back(temp);
    for(int i=index;i<A.size();i++)
    {
        if(i>index && A[i]==A[i-1])
            continue;
        //cout<<"i = "<<i<<" "<<"index = "<<index<<endl;
        temp.push_back(A[i]);
        recur_func(i+1, A, temp);
        temp.pop_back();
    }
}
vector<vector<int> > subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int> temp;
    ans.clear();
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
    subsetsWithDup(a);
    for(auto i:ans)
        print(i);
    return 0;
}