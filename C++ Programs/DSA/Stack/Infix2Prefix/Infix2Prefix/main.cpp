#include<iostream>
#include<stack>

using namespace std;

class Solution{
public:
    int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        else return -1;
    }
    
    string Infix2Post(string s){
        stack<char> st;
        string ans;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if((c>='A' && c<='Z')||
               (c>='a' && c<='z')||
               (c>='0' && c<='9')){
                ans += c;
            }
            else if(c=='(') st.push(c);
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && priority(c) < priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    
    string Prefix2Postfix(string s){
        reverse(s.begin(), s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s[i] = ')';
            }
            else if(s[i]==')'){
                s[i] = '(';
            }
        }
        s = Infix2Post(s);
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(){
    string s = "x+y*z/w+u";
    Solution myObj;
    cout << myObj.Prefix2Postfix(s)<<endl;
    return 0;
    
}
