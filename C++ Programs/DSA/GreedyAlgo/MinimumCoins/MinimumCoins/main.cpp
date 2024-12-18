#include<iostream>

using namespace std;

vector<int> MinimumCoins(vector<int>& a, int v){
    int minCount = 0;
    vector<int> ans;
    int n = a.size();
    for(int i=n-1; i>=0; i--){
        while(a[i]<=v){
            v -= a[i];
            ans.push_back(a[i]);
            minCount++;
        }
    }
    return ans;
}



int main(){
    vector<int> arr = {1,2,5,10,20,50};
    int v = 34;
    vector<int> ans = MinimumCoins(arr, v);
    int count = 0;
    
    cout<<"Minimum coins are: ";
    for(int num:ans){
        count++;
        cout<< num <<" ";
    }
    cout << endl;
    cout << count << endl;
    
    return 0;
}
