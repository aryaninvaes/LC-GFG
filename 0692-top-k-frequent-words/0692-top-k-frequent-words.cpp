class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(string &x : words){
            freq[x]++;
        }
        vector<pair<string, int>> vec;

        for(auto &it: freq){
            vec.push_back({it.first, it.second});
        }
        auto lambda=[](pair<string, int>& p1, pair<string, int>& p2){
            if (p1.second == p2.second){
                return p1.first < p2.first;   // lexicographically smaller first
            }
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        vector<string> result;
        for(int i=0; i<k; i++){
            result.push_back(vec[i].first);
        }
        return result;


    }
};