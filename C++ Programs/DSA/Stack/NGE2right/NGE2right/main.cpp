#include<iostream>

using namespace std;

vector<int> count_NGE(int n, vector<int>& arr, int queries, vector<int>& indices){
    vector<int> ans;
   
    
    for(int i=0;i<queries;i++){
        int index = indices[i];
        int count = 0;
        for(int j=index+1;j<n;j++){
            if(arr[j]>arr[index]) count++;
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    vector<int> arr = {3,4,2,7,5,8,10,6};
    int n = arr.size();
    int queries = 2;
    vector<int> indices = {0,5};
    
    vector<int> ans = count_NGE(n, arr, queries, indices);
    for(int num:ans){
        cout<<num<<" ";
    }
    return 0;
}
