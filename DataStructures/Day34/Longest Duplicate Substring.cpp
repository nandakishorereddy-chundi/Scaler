#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int check(string A, int k){
    if(k==0)
        return 1;
	int n = A.length();
	int q = 10000001;
	int b=31;
	int power = 1;
	for(int i=1;i<k;i++){
		power=(power*b)%q;
	}
	unordered_map<int, vector<int> >seen;
	int hash=0;
	for(int i=0;i<k;i++){
	    hash = (hash *b % q + A[i]) % q;
	}
	seen[hash].push_back(0);
	for(int i=k;i<n;i++){
		hash=(hash - power * A[i-k] % q + q)%q;
		hash = (hash * b % q + A[i]) % q;
		if(seen.count(hash)){
			for(auto it:seen[hash]){
				if(A.substr(it, k) == A.substr(i-k+1, k))
					return 1;
			}
		}
	    seen[hash].push_back(i-k+1);
	}
	return 0;
}

int bs(string A, int s, int e)
{
    int ans=1;
    while(s<=e)
    {
        //cout<<"s = "<<s<<" "<<"e = "<<e<<endl;
        int m=(s+e)/2;
        //cout<<"m = "<<m<<endl;
        if(check(A, m))
        {
            //cout<<"True"<<endl;
            ans=m;
            s=m+1;
        }
        else
        {
            //cout<<"False"<<endl;
            e=m-1;
        }
    }
    return ans;
}

int solve(string A) {
    int ans = bs(A, 0, A.length());
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}