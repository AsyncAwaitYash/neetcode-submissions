class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i<j){
            while(i<j && !isValid(s[i])){
                i++;
            }
 
            while(i<j && !isValid(s[j])){
                j--;
            }

            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    bool isValid(char c){
        return ((c>= 'A' && c<='Z') || (c>= 'a' && c<='z') || (c>= '0' && c<='9'));
    }
};
