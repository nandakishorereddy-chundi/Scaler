#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> &A) {
    int start, end, area;
    start = 0;
    end = A.size()-1;
    area = 0;
    while(start<end)
    {
        area = max(area, (end-start)*min(A[start], A[end]));
        if(A[start]>A[end])
            end--;
        else
            start++;
    }
    return area;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxArea(a)<<endl;
    return 0;
}