#include<iostream>
#include "../stdc++.h"
using namespace std;

float get_distance(vector<int> A)
{
    return sqrt((A[0]*A[0])+(A[1]*A[1]));
}

vector<vector<int> > solve(vector<vector<int> > &A, int B) {
    multimap<float, vector<int> > m;
    for(int i=0;i<A.size();i++)
        m.insert({get_distance(A[i]), A[i]});
    vector<vector<int> > ans;
    auto it = m.begin();
    for(int i=1;i<=B;i++)
    {
        ans.push_back(it->second);
        it++;
    }
    return ans;
}

void print(vector<vector<int> >&A)
{
    int r=A.size(),c=A[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int r,c,val,B;
    cin>>r>>c;
    vector<vector<int> >a, ans;
    for(int i=0;i<r;i++)
    {
        vector<int> temp;
        for(int j=0;j<c;j++)
        {
            cin>>val;
            temp.push_back(val);
        }
        a.push_back(temp);
    }
    cin>>B;
    ans = solve(a, B);
    print(ans);
    return 0;
}