class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()){
            return false;
        }
        string temp= s+s;
        int n=goal.length();
        int m=temp.length();
        for(int i=0 ; i<m-n+1 ; i++){
            if(temp.substr(i, n) == goal){
                return true;
            }
        }
        return false;
    }
};