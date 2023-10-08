class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        if(plants[0] > capacity){
            return 0;
        }
        int cap = capacity;
        int steps = 0;
        for(int i=0; i<plants.size(); i++){
            if(cap >= plants[i]){
                steps++;
            }
            else{
                cap = capacity;
                steps += 2*i + 1;
            }
            cap = cap-plants[i];
        }
        return steps;
    }
};