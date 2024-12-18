#include<iostream>

using namespace std;

struct Item{
    int value;
    int weight;
};

bool static comp(Item a, Item b){
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1>r2;
}

double fractional(int w, Item arr[], int n){
    double totalVal = 0.0;
    int currW = 0;
    
    sort(arr, arr+n, comp);
    for(int i=0;i<n;i++){
        if(currW + arr[i].weight <= w){
            currW += arr[i].weight;
            totalVal += arr[i].value;
        } else{
            int remain = w - currW;
            totalVal = (arr[i].value / (double)arr[i].weight) * (double) remain;
            break;
        }
    }
    
    return totalVal;
}

int main(){
    
}
