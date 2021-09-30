#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// function for constructing segment tree
int constructsegtree(int si,int sl,int sr,vector<int>& arr,vector<int>& segt){
	if(sl==sr)
		return segt[si]=arr[sl];
	int mid= (sl+sr)/2;
	// going to left and right side
	segt[si]= constructsegtree(2*si+1,sl,mid,arr,segt) + constructsegtree(2*si+2,mid+1,sr,arr,segt);
	return segt[si];
}

// function for finding sum over given range [l,r]
int findrangesum(int si,int sl,int sr,int l,int r,vector<int>& arr,vector<int>& segt){
	// sl and sr denote the present range of arr
	// l and r denote the range of query
	
	// no overlap so return 0
	if(sl>r || sr<l)
		return 0;
	
	// total overlap
	if(sl>=l && sr<=r)
		return segt[si];

	// partial overlap, so going to left and right
	int mid= (sl+sr)/2;
	return findrangesum(2*si+1,sl,mid,l,r,arr,segt) + findrangesum(2*si+2,mid+1,sr,l,r,arr,segt);

}

// function for updating the given index with the given value
void updatesegtree(int si,int sl,int sr,int index,int val,vector<int>& arr,vector<int>& segt){
	// if index is not inside bounds of [sl,sr]
	if(index<sl || index>sr)
		return;
	if(sl==sr){
		// here index==sl==sr, so update needs to happen 
		arr[index]=val;
		segt[si]=val;
	}
	else{
		int mid= (sl+sr)/2;
		if(index<=mid)
			updatesegtree(2*si+1,sl,mid,index,val,arr,segt);
		else
			updatesegtree(2*si+2,mid+1,sr,index,val,arr,segt);

		// updating the bottom first and then going up making the changes
		segt[si]= segt[2*si+1] + segt[2*si+2];
	}
}

int main(){
	// for fast input output
	ios_base::sync_with_stdio(false);  cin.tie(NULL);
	
	// initial work
	vector<int>arr={1,2,5,6,7,9};
	int n=arr.size();
	vector<int>segt(4*n);

	// constructing segment tree
	int si=0,sl=0,sr=n-1;	
	constructsegtree(si,sl,sr,arr,segt);

	// finding range sum 
	int l=1,r=4;
	int rsum= findrangesum(si,sl,sr,l,r,arr,segt);
	cout<<rsum<<"\n";

	// updating any index to some other value
	int index=2,val=8;
	updatesegtree(si,sl,sr,index,val,arr,segt);
}

