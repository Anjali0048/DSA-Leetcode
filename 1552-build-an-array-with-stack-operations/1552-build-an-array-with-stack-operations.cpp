class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> op;
        int index = 0;

        for(int i=1; i<=n; i++){
            if(index == target.size()){
                break;
            }
            if(target[index] == i){
                op.push_back("Push");
                index++;
            }
            else{
                op.push_back("Push");
                op.push_back("Pop");
            }
        }
        return op;
    }
};