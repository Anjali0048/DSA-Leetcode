class Solution {
public:
void nextPermutation(vector<int>& arr) {
    int l,r;
    int n = arr.size();
    for(l=n-2; l>=0; l--){
        if(arr[l]<arr[l+1]){
            break;
        }
    }
    if(l<0){
        reverse(arr.begin(), arr.end());
    }
    else{
        for(r=n-1; r>l; r--){
            if(arr[r]>arr[l]){
                break;
            }
        }
        swap(arr[l],arr[r]);
        reverse(arr.begin()+l+1, arr.end());
    }
}
};