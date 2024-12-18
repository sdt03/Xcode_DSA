#include<iostream>
#include<stack>
#include<vector>

using namespace std;


vector<int> NSE(vector<int>& arr){
    vector<int> ans(arr.size(),-1);
    stack<int> st;
    
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[i]<arr[st.top()]){ //(if stack is not empty and checks if current arr element is smaller than arr element of st.top)
            ans[st.top()] = arr[i]; //replaces smaller value at the index of st.top
            st.pop();
        }
        st.push(i); //push index of array element
    }
    return ans;
}

int main(){
    vector<int> arr = {4,8,2,1,6,10,5};
    vector<int> ans = NSE(arr);
    
    for(int num : ans){
        cout << (num==-1?-1:num) << " ";
    }
    
    return 0;
}
