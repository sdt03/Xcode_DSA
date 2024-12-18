#include<iostream>

using namespace std;

struct Jobs{
    int id;
    int deadline;
    int profit;
};

class Solution{
public:
    static bool comp(Jobs val1, Jobs val2){
        return val1.profit>val2.profit;
    }
    
    vector<int> JobScheduling(Jobs arr[], int n){
        
        sort(arr, arr+n, Solution::comp);
        
        int maxDeadline = -1;
        for(int i=0;i<n;i++){
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }
        
        int slot[maxDeadline+1];
        for(int i=1;i<=maxDeadline;i++){
            slot[i] = -1;
        }
        
        vector<int> ans;
        int maxProfit = 0, cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].deadline; j>0 ; j--){
                if(slot[j]==-1){
                    slot[j] = i;
                    cnt++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        ans.push_back(cnt);
        ans.push_back(maxProfit);
        return ans;
    }
};

int main(){
    int n = 4;
    Jobs arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};
    
    Solution obj;
    
    vector<int> ans = obj.JobScheduling(arr, n);
    
    for(int num: ans){
        cout << num << " " << endl;
    }
    return 0;
}
