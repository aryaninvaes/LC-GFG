class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> st1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> st2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> st3 = {'z','x','c','v','b','n','m'};
        vector<string> result;

        for(string &word: words){
            vector<bool> check(3, false);
            for(char &c: word){
                char ch = tolower(c); 
                if(st1.count(ch)){
                    check[0] = true;
                }
                if(st2.count(ch)){
                    check[1] = true;
                }
                if(st3.count(ch)){
                    check[2] = true;
                }
            }
            int count = 0;
            for(bool t: check){
                if(t==true) count++;
            }
            if(count==1){
                result.push_back(word);
            }
        }
        return result;


    }
};