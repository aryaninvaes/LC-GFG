class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1;
        long long end = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        long long ans=end;

        while(start<=end){
            long long mid = start+ (end-start)/2;
                long long sum=0;
                for(int i=0; i< time.size(); i++){
                    sum=sum+(mid/time[i]);
                    if(sum>=totalTrips){
                        break;
                    }
                }
                
                if(sum>=totalTrips){
                    ans=mid;
                    end=mid-1;
                }else{
                    start=mid+1;
                }
        }
        return ans;
    }
};