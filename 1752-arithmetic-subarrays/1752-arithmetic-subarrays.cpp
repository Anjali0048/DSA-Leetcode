class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans(n, true);

        for (int i = 0; i < n; i++) {
            int a = l[i];
            int b = r[i];

            vector<int> temp(nums.begin() + a, nums.begin() + b + 1);
            sort(temp.begin(), temp.end());

            int diff = temp[1] - temp[0];

            for (int j = 0; j < temp.size() - 1; j++) {
                int ele = temp[j + 1] - temp[j];
                if (ele != diff) {
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};
