class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mpp;
        for(auto it: tasks){
            mpp[it]++;
        }
        int count_round = 0;
        for(auto it: mpp){
            int tasks = it.second;
            if(tasks==1) return -1;
            if(tasks%3==0) count_round+= tasks/3;
            else{
                count_round+= tasks/3 + 1;
            }
        }
        return count_round;
    }
};