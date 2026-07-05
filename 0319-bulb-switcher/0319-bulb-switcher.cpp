class Solution {
public:
    int bulbSwitch(int n) {
        long long newn=n;
        long long temp=1;
        long long count=0;

        while(temp <= n){
            if(temp * temp <=newn){
                count++;
            }
            temp= temp+1;
        }
        return count;
    }
};