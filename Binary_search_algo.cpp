// problem take from EKO-eko of SPOJ
// problem link: https://www.spoj.com/problems/EKO/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// implementation of function for checking if the current mid will work or not.
bool isok(ll mid, ll wood, vector<ll>& treeheights){
    ll sumofwoods=0;
    for(ll i=0;i<treeheights.size();i++){
        if(treeheights[i]> mid){
            sumofwoods+= (treeheights[i]-mid);
        }
        if(sumofwoods>= wood)
            return true;
    }
    return false;
}

// implementation of function for binary_search_algo
void binary_search_algo(ll n, ll wood,vector<ll>& treeheights){
    // setting the starting low and high points.
        ll low=0,high= 1e+9,best=-1;
        while(low<=high){
            ll mid= (low+high)/2;
            if(isok(mid,wood,treeheights)){
                best=mid;
                low= mid+1;
            }
            else{
                high=mid-1;
            }
        }
        // checking if we have got a valid answer or not
        if(best!=-1)
            cout<<best<<nline;
        else
            cout<<"not possible"<<nline;
}

int main(){
    // for fast input output
    ios_base::sync_with_stdio(false);  cin.tie(NULL);

    // number of trees and wood we need
    ll n=4, wood=7;
    
    // vector having treeheights
    vector<ll>treeheights={15,20,10,17};

    //function for finding the optimum height of cutting height.
    binary_search_algo(n,wood,treeheights);
}
