class Solution {
public:

    void function(vector<int>& potions, long long temp,
                  vector<int>& result) {

        int left = 0;
        int right = potions.size() - 1;
        int ans = potions.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (potions[mid] >= temp) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result.push_back(potions.size() - ans);
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(), potions.end());

        vector<int> result;

        for (int spell : spells) {
            long long temp = (success + spell - 1) / spell; // ceil
            function(potions, temp, result);
        }

        return result;
    }
};