#include<iostream>
#include<string>
using namespace std;

int solve(string A) {
    string B=A+A;
    B=B.substr(1, B.length()-2);
    int i=0,j=0;
    while(i<B.length())
    {
        if(B[i]==A[j])
        {
            j++;
            i++;
            if(j==A.length())
                return 1;
        }
        else
        {
            j=0;
            if(B[i]==A[j])
                continue;
            else
                i++;
        }
    }
    return 0;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}