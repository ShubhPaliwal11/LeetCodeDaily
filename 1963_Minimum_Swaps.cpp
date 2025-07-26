class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        int close = 0;
        int swap = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']' && open == 0) {
                swap++;
            }else if(s[i] == '['){
                open++;
            }else{
                open--;
            }
        }
        return (swap+1)/2;
    }
};

// the intution is really cool , i must revise this!
