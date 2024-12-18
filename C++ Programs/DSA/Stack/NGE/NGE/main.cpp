#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> NGE(vector<int>& arr, int n){
    vector<int> ans(n,-1);
    stack<int> st;
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i] >= st.top()){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,3,4,2};
    int n = arr.size();
    
    vector<int> ans = NGE(arr, n);
    for(int num:ans){
        cout << num << " ";
    }
    return 0;
}
