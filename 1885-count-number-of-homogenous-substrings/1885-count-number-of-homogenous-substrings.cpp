class Solution {
public:
    
    int countHomogenous(string s) {
        long long ans = 0;
        int left = 0;

        // TLE 

        // for(int i=0; i<s.size(); i++){
        //     int count=1;
        //     for(int j=i+1; j<s.size(); j++){
        //         if(s[i] == s[j]){
        //             count++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     ans += count;
            
        // }

        for(int right=0; right<s.size(); right++){
            if(s[left] == s[right]){
                ans += right-left+1;
            }
            else{
                ans += 1;
                left = right;
            }
        }
        
        return (ans % (1000000007));
    }
};