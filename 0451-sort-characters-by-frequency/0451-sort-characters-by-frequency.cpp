class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for(auto x: s){
            mpp[x]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto it : mpp){
            maxHeap.push({it.second, it. first});
        }
        string temp="";
        while(!maxHeap.empty()){
            int tempNum=maxHeap.top().first;
            while(tempNum--){
                temp+=maxHeap.top().second;
            }
            maxHeap.pop();
        }
        return temp;
        
    }
};