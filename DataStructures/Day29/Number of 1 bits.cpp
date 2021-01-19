#include<iostream>
#include<vector>
using namespace std;

int numSetBits(unsigned int A) {
    int a = 1, cnt=0;
    for(int i=0;i<32;i++)
    {
        if(A&a)
            cnt++;
        a = a<<1;
    }
    return cnt;
}

int main()
{
    unsigned int n;
    cin>>n;
    cout<<numSetBits(n)<<endl;
    return 0;
}