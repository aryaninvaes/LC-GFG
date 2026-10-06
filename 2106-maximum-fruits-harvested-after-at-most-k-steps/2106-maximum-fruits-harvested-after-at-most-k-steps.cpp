class Solution {
public:

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        int n = fruits.size();

        vector<int> prefixSum(n);
        vector<int> positions(n);

        for(int i = 0; i < n; i++){
            positions[i] = fruits[i][0];

            prefixSum[i] = fruits[i][1];

            if(i > 0)
                prefixSum[i] += prefixSum[i-1];
        }

        int max_fruits = 0;

        for(int d = 0; d <= k/2; d++){

            // Go d steps left first
            // Then use remaining k - 2*d steps to go right

            int remaining = k - 2*d;

            int i = startPos - d;
            int j = startPos + remaining;

            int left = lower_bound(positions.begin(), positions.end(), i)
                       - positions.begin();

            int right = upper_bound(positions.begin(), positions.end(), j)
                        - positions.begin() - 1;

            if(left <= right){

                int total = prefixSum[right];

                if(left > 0)
                    total -= prefixSum[left-1];

                max_fruits = max(max_fruits, total);
            }


            // Go d steps right first
            // Then use remaining steps to go left

            j = startPos + d;
            i = startPos - remaining;

            left = lower_bound(positions.begin(), positions.end(), i)
                   - positions.begin();

            right = upper_bound(positions.begin(), positions.end(), j)
                    - positions.begin() - 1;

            if(left <= right){

                int total = prefixSum[right];

                if(left > 0)
                    total -= prefixSum[left-1];

                max_fruits = max(max_fruits, total);
            }
        }
        return max_fruits;
    }
};