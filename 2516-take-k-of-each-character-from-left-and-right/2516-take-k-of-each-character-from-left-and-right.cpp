class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int minutes = s.length();

        vector<int> arr(3,0);

        for(char &st: s){
            arr[st-'a']++;
        }
        if(arr[0] < k || arr[1] < k || arr[2] < k){
            return -1;
        }

        int i=0; int j=0; int maxWin = 0;
        while(j<n){
            arr[s[j]-'a']--;
            
            while(arr[0]<k || arr[1]<k || arr[2]<k){
                arr[s[i]-'a']++;
                i++;
            }
            maxWin = max(maxWin, j-i+1);
            j++;
        }
        return n-maxWin;
    }
};