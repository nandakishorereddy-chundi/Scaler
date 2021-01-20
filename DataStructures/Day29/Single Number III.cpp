#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> &A) {
    int xor_val = 0;
    for(auto i:A)
        xor_val ^= i;
    int x=0, y=0, pos=1, cnt=0;
    for(int i=0;i<32;i++)
    {
        if(xor_val&pos)
            break;
        cnt++;
        pos<<=1;
    }
    pos=1;
    for(auto i:A)
    {
        if(i&(pos<<cnt))
            x^=i;
        else
            y^=i;
    }
    vector<int> sol;
    if(x<y)
    {
        sol.push_back(x);
        sol.push_back(y);
    }
    else
    {
        sol.push_back(y);
        sol.push_back(x);
    }
    return sol;
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
    ans = solve(a);
    print(ans);
    return 0;
}