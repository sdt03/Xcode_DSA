#include<iostream>
#include<map>

using namespace std;
//OPTIMAL SOLUTION WHEN THE ARRAY HAS ZERO AND NEGATIVE INTEGERS: (BETTER SOLUTION)
int longestsubarraywithSum(vector<int>& arr, long long k){
    int maxLen = 0;
    map<long long, int> preSum;
    long long sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSum.find(rem)!=preSum.end()){
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }
        if(preSum.find(sum)==preSum.end()){
            preSum[sum] = i;
        }
    }
    
    return maxLen;
}

//TWO POINTER APPROACH
int longestSubarray(vector<int>& arr, long long k){
    int maxLen=0;
    int left = 0, right = 0;
    long long sum = arr[0];
    
    while(right<arr.size()){
        while(left <= right && sum>k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right<arr.size()) sum+=arr[right];
        
    }
    return maxLen;
}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    
    long long k = 6;
    int maxLen = longestSubarray(arr, k);
    cout<<maxLen<<endl;
    return 0;
}

