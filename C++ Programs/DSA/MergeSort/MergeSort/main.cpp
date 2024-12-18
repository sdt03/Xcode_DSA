#include<iostream>

using namespace std;

void merge(vector<int> &arr, int l, int m, int h){
    vector<int> temp;
    int left = l;
    int right = m+1;
    
    while(left<=m && right<=h){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=m){
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right<=h){
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i = l; i <= h; i++){
        arr[i] = temp[i-l];
    }
}

void mergeSort(vector<int>& arr, int l, int h){
    if(l>=h) return;
    int m = (l+h)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, h);
    merge(arr, l, m, h);
}

int main(){
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = arr.size();
    
    cout<<"Array before Sorting: " << endl;
    for(int num : arr){
        cout << num << " ";
    }
    
    mergeSort(arr, 0, n-1);
    cout<<endl;
    cout <<"Array after sorting: " <<endl;
    for(int num : arr){
        cout<< num << " ";
    }
    return 0;
}



