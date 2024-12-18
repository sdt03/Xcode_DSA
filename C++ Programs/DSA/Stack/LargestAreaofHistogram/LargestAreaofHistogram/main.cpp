#include<iostream>
#include<stack>

using namespace std;

int largestArea(vector<int>& heights){
    int maxArea = 0;
    stack<int> st;
    for(int i=0;i<heights.size();i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int element = heights[st.top()];
            st.pop();
            int nse;
            if(st.empty())
                nse = i;
            else
                nse = i - st.top() - 1;
            maxArea = max(maxArea, element*nse);
        }
        st.push(i);
    }
    return maxArea;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int area = largestArea(heights);
    
    cout << area << " ";
    return 0;
}
