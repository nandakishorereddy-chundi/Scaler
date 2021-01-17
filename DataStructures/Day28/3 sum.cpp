#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int p1, p2, sum=A[0]+A[1]+A[2], val=INT_MAX;
    for(int i=0;i<=A.size()-3;i++)
    {
        p1 = i+1;
        p2 = A.size()-1;
        while(p1<p2)
        {
            if(A[p1]+A[p2]==B-A[i])
                return B;
            else if(A[p1]+A[p2]>B-A[i])
                p2--;
            else
                p1++;
            if(abs(A[i]+A[p1]+A[p2]-B)<val && p1<p2)
            {
                //cout<<i<<" "<<p1<<" "<<p2<<endl;
                val = abs(A[i]+A[p1]+A[p2]-B);
                sum = A[i]+A[p1]+A[p2];
            }
        }
    }
    return sum;
}


int main()
{
    int n,b;
    cin>>n>>b;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(a, b)<<endl;
    return 0;
}