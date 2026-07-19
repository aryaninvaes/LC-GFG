class Solution {
public:
    string toLowerCase(string s) {
        for(auto &it: s){
            if(it>='A' && it<='Z'){
                it = it + ('a' - 'A');
            }
        }
        return s;
    }
};