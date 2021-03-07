#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<int> >ans;

void print(vector<int>&A)
{
    for(auto i:A)
        cout<<i<<" ";
    cout<<endl;
}

void recur_func(vector<int> &A, unordered_map<int, int>&umap, vector<int> &temp)
{
    if(temp.size()==A.size())
    {
        ans.push_back(temp);
        return;
    }
    else
    {
        for(auto itr:umap)
        {
            if(umap[itr.first]==0) continue;
            umap[itr.first]--;
            temp.push_back(itr.first);
            recur_func(A, umap, temp);
            temp.pop_back();
            umap[itr.first]++;
        }
    }
}

vector<vector<int> > permute(vector<int> &A) {
    ans.clear();
    unordered_map<int, int> umap;
    sort(A.begin(), A.end());
    for(auto i:A)
        umap[i]++;
    vector<int> temp;
    recur_func(A, umap, temp);
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