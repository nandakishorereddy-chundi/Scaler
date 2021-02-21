#include<iostream>
#include<string>
using namespace std;

string solve(string A) {
    int cnt=0;
    for(int i=0;i<A.size()/2;i++)
    {
        if(A[i]!=A[A.size()-i-1])
        {
            cnt++;
            if(cnt>1)
                return "NO";
        }
    }
    if(cnt==0 && A.size()%2==0)
        return "NO";
    return "YES";
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}