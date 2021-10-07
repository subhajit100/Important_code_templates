#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

 //Function to find maximum of each subarray of size k.
    vector <int> max_subarrays_using_deque(vector<int>arr, int n, int k)
    {
        vector<int>ans;
        // dq for storing the <value,index> pair.
        deque<pair<int,int>>dq;
        for(int i=0;i<n;i++){
            // for removing out of window elements
            while(!dq.empty() && dq.front().second<= i-k)
                dq.pop_front();
            
            // for inserting into the back wisely, i.e removing all elements<= arr[i] from the back
            while(!dq.empty() && dq.back().first<=arr[i])
                dq.pop_back();
            
            // pushing the current element    
            dq.push_back(make_pair(arr[i],i));
            
            // pushing the maximum into the ans vector from the front of dq.
            if(i>=k-1)
                ans.push_back(dq.front().first);
        }
        return ans;
    }
int main(){
    // for fast input output
    ios_base::sync_with_stdio(false);  cin.tie(NULL);

    int n,k;
    cin>>n>>k;

   // vector arr 
    vector<int>arr;

    // inserting values into vector
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //function for finding maximum of all subarrays of size k using deque..
    vector<int>ans= max_subarrays_using_deque(arr,n,k);

    // showing the maximum subarray vector
    for(auto it:ans){
        cout<<it<<" ";
    }
}
