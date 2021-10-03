#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// implementation of function for merging intervals
void mergeintervals(vector<pair<ll,ll>>& vec){
    // custom sort function to sort the vec based on starting values
    sort(vec.begin(),vec.end(),[](pair<ll,ll>& p1,pair<ll,ll>& p2){
        // if first values are equal then check for second values
        if(p1.first==p2.first)
             return p1.second<p2.second;
        return p1.first<p2.first;
    });

    // now run a loop over sorted vec to merge intervals
    int idx=0;
    for(int i=1;i<vec.size();i++){
        if(vec[idx].second>=vec[i].first){
            vec[idx].second= max(vec[idx].second,vec[i].second);
        }
        else{
            idx++;
            vec[idx]=vec[i];
        }
    }
    // till 'idx' only, we have the merged intervals, so erase the elements after that
    vec.erase(vec.begin()+idx+1,vec.end());
}

int main(){
    // for fast input output
    ios_base::sync_with_stdio(false);  cin.tie(NULL);

    // vector of pairs containing intervals
    vector<pair<ll,ll>>vec={{5,9},{4,6},{3,7},{13,19},{11,14}};

    //function for merging the intervals.
    mergeintervals(vec);

    // showing the merged intervals
    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<"\n";
    }
}
