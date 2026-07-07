class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> freq;  //no, frequency
        for(auto it:arr){
            freq[it]++;
        }
        set<int> st;
        for(auto it: freq){
            st.insert(it.second);
        }
        if(st.size()==freq.size()){
            return true;

        }
        return false;
    }
};