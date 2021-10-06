#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nline "\n"

// checking if pat is equal to substring of text starting from index i
bool checkequal(int i, string text, string pat){
	int x=0;
	for(;x<pat.size();x++,i++){
		if(text[i]!=pat[x])
			return false;
	}
	return true;
}

vector<int> string_matching_using_Rabin_Karp(string text,string pat){
	vector<int>ans;

	int n= text.size();
	int m= pat.size();

	// if size of text is lesser than pat
	if(m>n)
		return ans;

	int prime=101;
	int d=256;
	int h= 1;

	// highest power on pat
	for(int i=0;i<m-1;i++)
		h= (h*d)%prime;

	// finding patsum and textsum;
	int patsum=0, sum=0;
	for(int i=0;i<m;i++){
		patsum= (d*patsum + pat[i])% prime ;
		sum = (d*sum + text[i])% prime;
	}
    
	// traversing every window of text
	for(int i=0;i<=(n-m);i++){
		// if both sum and patsum still we need to check whether they are equal or not
		if(sum==patsum && checkequal(i,text,pat))
			ans.push_back(i+1);

		if(i<(n-m)){
			// removing the leftmost character of window
			sum = sum- ((text[i])* h);
			// if sum becomes negative
			while(sum<0)
				sum+=prime;
			sum%=prime;

			// shifting the present window by 1
			sum*=d;
			sum%=prime;

			// adding the rightmost character of window
			sum+= text[i+m];
			sum%=prime;

		}
	}
	return ans;

}

int main(){
	// for fast input output
	ios_base::sync_with_stdio(false);  cin.tie(NULL);

    string text="ABCDEFGHEFNABCGHNMNO";
    string pat="AB";
    vector<int>ans= string_matching_using_Rabin_Karp(text,pat);
    for(auto it:ans)
    	cout<<it<<" ";
    cout<<nline;
}

