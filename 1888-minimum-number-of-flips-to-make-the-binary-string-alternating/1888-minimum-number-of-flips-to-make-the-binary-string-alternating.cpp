class Solution {
public:
    int minFlips(string s) {
        int n=s.length();

        s = s+s;

        //s1= 01010101;
        //s2= 10101010;
        string s1, s2;

        for(int i=0; i<2*n; i++){
            s1 += (i%2 ? '0':'1');
            s2 += (i%2 ? '1':'0');
        }

        int flip1=0;
        int flip2=0;
        for(int i=0; i<n; i++){
            if(s1[i] != s[i]){
                flip1++;
            }
            if(s2[i] != s[i]){
                flip2++;
            }
        }

        int left=1;
        int right=n;
        int ans=INT_MAX;
        while( right < 2*n ){
            if(s[left-1] != s1[left-1]){
                flip1--;
            }
            if(s[left-1] != s2[left-1]){
                flip2--;
            }
            if(s[right] != s1[right]){
                flip1++;
            }
            if(s[right] != s2[right]){
                flip2++;
            }
            int flip= min(flip1, flip2);
            ans= min(ans, flip);
            left++;
            right++;
        }
        return ans;

        
    }
};