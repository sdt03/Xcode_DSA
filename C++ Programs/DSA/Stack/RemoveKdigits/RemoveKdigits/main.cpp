#include<iostream>
#include<string>
#include<vector>

using namespace std;

string removekDigits(string num, int k){
    if(num.length()==k) return "0";
    
    string ans = "";
    stack<char> st;
    for(char ch : num){
        while(!st.empty() && st.top() > ch && k>0){
            st.pop();
            k--;
        }
        st.push(ch);
    }
        while(k>0){
            st.pop();
            k--;
        }
        
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    
    if(ans.size()>0 && ans.back()=='0'){
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0":ans;
}

int main(){
    string num = "1432219";
    string ans = removekDigits(num, 3);
    
    cout << ans;
    return 0;
    
}
