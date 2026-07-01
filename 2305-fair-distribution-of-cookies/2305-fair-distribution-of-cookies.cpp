class Solution {
public:
    int result;
    int n;

    void solve(int index, vector<int>&children, vector<int>& cookies, int k){
        if(index>=n){
            int unfairness= *max_element(children.begin(), children.end());    
            result = min(result, unfairness);
            return;
        }
        int cookie= cookies[index];
        for(int i=0; i<k; i++){
            children[i]=children[i]+cookie;
            solve(index+1, children, cookies, k);
            children[i]=children[i]-cookie;
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        result= INT_MAX;
        vector<int> children(k,0);
        solve(0, children, cookies, k);

        return result;
    }
};