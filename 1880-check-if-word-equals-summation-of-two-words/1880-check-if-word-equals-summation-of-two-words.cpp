class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int temp1=0;
        for(auto x: firstWord){
            temp1 = temp1 * 10 + (x-'a');
        }
        int temp2=0;
        for(auto x: secondWord){
            temp2 = temp2 * 10 + (x-'a');
        }
        int temp3=0;
        for(auto x: targetWord){
            temp3 = temp3 * 10 + (x-'a');
        }
        return (temp1+temp2 == temp3);

        
    }
};