class Solution {
public:

    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }

    int myAtoi(string s) {
        int n = s.size();

        if(n==0) return 0;

        int index = 0;

        // skipping whitespaces
        while(index < n && s[index]==' '){
            index++;
        }
        // handle sign
        bool isNeg = false;
        if(index < n){
            if(s[index] == '-'){
                isNeg = true;
                index++;
            }
            else if(s[index] == '+'){
                ++index;
            }
        }
        int res = 0;
        while(index<n && isDigit(s[index])){
            int digit = s[index]-'0';
            if(res > (INT_MAX/10) || (res == (INT_MAX/10) && digit > 7)){
                return isNeg ? INT_MIN : INT_MAX;
            }
            res = (res*10) + digit;
            index++;
        }
        return isNeg ? -res : res;
    }


};