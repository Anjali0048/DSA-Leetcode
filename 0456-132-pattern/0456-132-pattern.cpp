class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int> st;
        int third = INT_MIN;

        int n = nums.size()-1;
        for(int i=n; i>=0; i--){
            if(nums[i] < third){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};