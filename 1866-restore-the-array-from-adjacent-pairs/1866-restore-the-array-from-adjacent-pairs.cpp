class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;

        for(const auto &pair : adjacentPairs){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        vector<int> res;

        for(const auto &entry : graph){
            if(entry.second.size() == 1){
                res = {entry.first, entry.second[0]};
                break;
            }
        }

        while(res.size() < adjacentPairs.size() + 1){
            int last = res[res.size() - 1];
            int prev = res[res.size() - 2];
            const vector<int> &candidates = graph[last];
            int nextEle = (candidates[0] != prev) ? candidates[0] : candidates[1];
            res.push_back(nextEle);
        }
        return res;
    }
};