class Solution {
public:
    int maxPower(string s) {
        int first=s[0];
        int n=s.length();
        int count=0;
        int maxi=0;

        for(int i=0; i<n; i++){
            if(s[i]==first){
                count++;
                maxi= max(count, maxi);
            }else{
                count=1;
                first=s[i];
            }
        }
        return maxi;
        
    }
};