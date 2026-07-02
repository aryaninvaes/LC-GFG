// class Solution {
// public:
//     bool hasDuplicate(string temp, string s) {
//     vector<int> freq(26, 0);

//     for(char c : temp) {
//         if(freq[c-'a']) return false;
//         freq[c-'a']++;
//     }

//     for(char c : s) {
//         if(freq[c-'a']) return false;
//         freq[c-'a']++;
//     }

//     return true;
//     }

//     int solve(int i, vector<string>& arr, string temp, int n){
//         if(i>=n){
//             return temp.length();
//         }

//         int include=0;
//         int exclude=0;
//         if(hasDuplicate(temp, arr[i])){
//             exclude=solve(i+1, arr, temp,n);
//         }else{
//             exclude=solve(i+1, arr, temp, n);
//             include=solve(i+1, arr, temp+arr[i],n);
//         }
//         return max(include, exclude);
//     }

//     int maxLength(vector<string>& arr) {
//         string temp="";
//         int n=arr.size();

//         int i=0;
//         return solve(i, arr, temp, n);

//     }
// };








// // class Solution {
// // public:
// //     void solve(vector<sting>& arr, int index, int len){
// //         if(index>=n){

// //         }
// //         string word= arr[index];
// //         bool flag=true;
// //         for(auto it: word){
// //             if(temp[it-'a']!=0){
// //                 //cant take ie-skip
// //                 flag=false;
// //             }
// //         }
// //         int word_len= word.length();
// //         if(!flag){
// //             continue;
// //         }else{
// //             int take = solve(arr, index+1, len+word_len, temp);
// //             int not_take= solve(arr, index+1, len, temp);

// //         }

        

// //     }
// //     int maxLength(vector<string>& arr) {
// //         vector<int> temp(26,0);
// //         int len=0;
// //         sovle(arr,0,len,temp);
// //         return len;
// //     }
// // };



class Solution {
public:
    bool hasDuplicate(string temp, string s) {
        vector<int> freq(26, 0);

        for(char c : temp) {
            if(freq[c-'a']) return false;
            freq[c-'a']++;
        }

        for(char c : s) {
            if(freq[c-'a']) return false;
            freq[c-'a']++;
        }

        return true;
    }

    int solve(int i, vector<string>& arr, string temp, int n) {
        if(i == n)
            return temp.length();

        int exclude = solve(i + 1, arr, temp, n);

        int include = 0;
        if(hasDuplicate(temp, arr[i])) {
            include = solve(i + 1, arr, temp + arr[i], n);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        return solve(0, arr, "", arr.size());
    }
};