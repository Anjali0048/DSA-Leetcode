class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto i : nums){
            pq.push(i);
        }
        int n = pq.top();
        pq.pop();
        int m = pq.top();
        pq.pop();
        int product = (n-1) * (m-1);
        
        return product;
    }
};