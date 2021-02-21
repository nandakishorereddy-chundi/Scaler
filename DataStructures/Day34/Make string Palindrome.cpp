#include<iostream>
#include<string>
using namespace std;

int solve(string A) {
    string revString = string(A.rbegin(), A.rend());
    int cnt=0, ptr=0;
    for(int i=0;i<revString.size();i++)
    {
        if(revString[i]!=A[ptr])
        {
            cnt=ptr=0;
        }
        if(revString[i]==A[ptr])
        {
            cnt++;
            ptr++;
        }
    }
    return A.size()-cnt;
}

int main()
{
    string a;
    cin>>a;
    cout<<solve(a)<<endl;
    return 0;
}