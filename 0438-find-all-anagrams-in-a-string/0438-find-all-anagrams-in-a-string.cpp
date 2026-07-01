class Solution {
public:
    bool isZero(vector<int>& counter){
        for(auto &it : counter){
            if(it!=0){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n= s.length();

        vector<int> counter(26,0);
        for(auto &i : p){ 
            counter[i - 'a']++;
        }

        int i=0;
        int j=0;
        vector<int> result;
        int k=p.length();

        while(j<n){
            counter[s[j]-'a']--;
            //checking if window size if equal to length of p and is all elements of counter is equal to 0
            if(j-i+1==k){
                if(isZero(counter)){
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
        
    }
};