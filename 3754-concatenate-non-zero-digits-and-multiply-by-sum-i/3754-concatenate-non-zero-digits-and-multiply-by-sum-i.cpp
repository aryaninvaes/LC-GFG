class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp=n;
        int sum=0;
        vector<int> vec;
        while(n!=0){
            sum += n % 10;
            if(n%10 !=0){
                vec.push_back(n%10);
            }
            n /= 10;
        }
        
        reverse(vec.begin(), vec.end());

        long long product = 0;
        for (int d : vec) {
            product = product * 10 + d;
        }

        return product * sum;
    }
};