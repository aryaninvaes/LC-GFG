class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size() - 1;
        vector<int> result;

        while (n >= 0 || k > 0) {
            if (n >= 0)
                k += num[n];

            result.push_back(k % 10);
            k /= 10;
            n--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};