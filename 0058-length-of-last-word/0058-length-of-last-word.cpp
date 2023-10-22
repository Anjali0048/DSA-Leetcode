class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int flag = 0;

        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' ' && flag)
                break;
            if(s[i] != ' '){
                cnt++;
                flag =1;
            }
        }
        return cnt;
    }
};