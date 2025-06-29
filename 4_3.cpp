
class Solution {
  public:
    vector<vector<int>> findWays(int N, int r, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(arr, r, 0, current, result);
        return result;
        
    }
    void backtrack(vector<int>& arr, int r, int start, vector<int>& current, vector<vector<int>>& result){
        if(current.size() == r){
            result.push_back(current);
            return;
        }
        for(int i = start; i < arr.size(); i++){
            current.push_back(arr[i]);
            backtrack(arr, r, i+1, current, result);
            current.pop_back();
            int temp = arr[i];
            while(arr[i+1] == temp) i++;
        }
        
    }
};
