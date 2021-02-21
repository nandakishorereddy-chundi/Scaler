#include<iostream>
#include<string>
using namespace std;

string addBinary(string A, string B) {
    int i=A.size()-1, j=B.size()-1;
    char c='0';
    string ans="";
    while(i>=0 && j>=0)
    {
        if(A[i]=='1' && B[j]=='1')
        {
            if(c=='1')
                ans+='1';
            else
                ans+='0';
            c='1';
        }
        else if(A[i]=='0' && B[j]=='0')
        {
            if(c=='1')
                ans+='1';
            else
                ans+='0';
            c='0';
        }
        else
        {
            if(c=='1')
            {
                ans+='0';
                c='1';
            }
            else
            {
                ans+='1';
                c='0';
            }
        }
        i--;
        j--;
    }
    while(i>=0)
    {
        if(A[i]=='1')
        {
            if(c=='1')
            {
                ans+='0';
                c='1';
            }
            else
            {
                ans+='1';
                c='0';
            }
        }
        else
        {
            if(c=='1')
            {
                ans+='1';
                c='0';
            }
            else
            {
                ans+='0';
                c='0';
            }
        }
        i--;
    }
    while(j>=0)
    {
        if(B[j]=='1')
        {
            if(c=='1')
            {
                ans+='0';
                c='1';
            }
            else
            {
                ans+='1';
                c='0';
            }
        }
        else
        {
            if(c=='1')
            {
                ans+='1';
                c='0';
            }
            else
            {
                ans+='0';
                c='0';
            }
        }
        j--;
    }
    if(c=='1')
        ans+='1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<addBinary(s1, s2)<<endl;
    return 0;
}