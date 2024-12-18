#include <iostream>
#include<stack>
#include<map>
#include<cstring>

using namespace std;
    bool isValid(string s){
        stack<char> st;
        map<char, char> mapping;
        mapping['}'] = '{';
        mapping[')'] = '(';
        mapping[']'] = '[';
        
        map<char, char>::iterator itr;
        
        for(int i=0; i<s.length();i++){
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]=='}'||s[i]==')'||s[i]==']'){
                if(st.empty()){
                    return false;
                }
                else{
                    char temp = st.top();
                    itr = mapping.find(s[i]);
                    if(temp==itr->second){
                        st.pop();
                    }
                    else
                        return false;
                }
            }
        }
        return st.empty()?true:false;
        
    }
    


int main() {
    char A[]="()";
    cout << isValid(A) << endl;
    
    return 0;
}
