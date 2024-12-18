#include<iostream>

using namespace std;

int sumofAllsubarrays(vector<int>& a, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=i;j<n;j++){
            temp += a[j];
        }
        sum += temp;
    }
    return sum;
}

int main(){
    vector<int> a = {1,2,3,4};
    int n = a.size();
    
    int sum = sumofAllsubarrays(a, n);
    cout << sum << endl;
    return 0;
}
