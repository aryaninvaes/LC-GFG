class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> st2;
        for(auto x: s){
            if(x=='#'){
                if(!st.empty()){
                    st.pop();
                }else{
                    continue;
                }
            }else{
                st.push(x);
            }
        }
        for(auto x: t){
            if(x=='#'){
                if(!st2.empty()){
                    st2.pop();
                }else{
                    continue;
                }
            }else{
                st2.push(x);
            }
        }
        if(st.size() != st2.size()) return false;
        while(!st.empty()){
            if(st.top() != st2.top()) return false;
            st.pop();
            st2.pop();
        }
        return true;
    }
};