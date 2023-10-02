class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;
        
        vector<string> ans;

        int n= score.size();

        for(int i=0; i<n ;i++){
            pq.push(score[i]);
        }

        int i=1;
        map<int, string> m;

        while(!pq.empty()){
            if(i==1){
                m.insert({ pq.top(), "Gold Medal"});
                pq.pop();
                i++;
            }
            else if(i==2){
                m.insert({ pq.top(), "Silver Medal"});
                pq.pop();
                i++;
            }
            else if(i==3){
                m.insert({ pq.top(), "Bronze Medal"});
                pq.pop();
                i++;
            }
            else{
                string st = to_string(i);
                m.insert({ pq.top(), st });
                pq.pop();
                i++;
            }
        }
        for(int i=0; i<n; i++){
            ans.push_back(m[score[i]]);
        }
        return ans;
    }
    
};