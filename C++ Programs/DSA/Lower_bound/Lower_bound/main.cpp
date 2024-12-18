#include<iostream>

using namespace std;

int lower_bound(vector<int>& arr, int target, int n){
    int ans = 0;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]>=target){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int upper_bound(vector<int>& arr, int target, int n){
    int ans = 0;
    int low = 0, high = n-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
    int n = arr.size();
    int ans = upper_bound(arr, 10, n);
    cout<<ans<<endl;
    return 0;
}
