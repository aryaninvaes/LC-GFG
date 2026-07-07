class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for(auto x: piles){
            maxHeap.push(x);
        }
        while(k--){
            int num=maxHeap.top();
            maxHeap.pop();
            num -= floor(num/2);
            maxHeap.push(num);
        }
        int sum=0;
        while(!maxHeap.empty()){
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};