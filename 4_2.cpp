// User function Template for C++

class Solution {
  public:
    int min_operations(int n, vector<int>& arr, vector<int>& brr) {
        // code here
        int op = 0;
        queue<int> b;
        deque<int> a;
        for(int i=0; i<n; i++){
            a.push_back(arr[i]);
            b.push(brr[i]);
        }
        while(!b.empty()){
            if(a.front() == b.front()){
                a.pop_front();
                b.pop();
            }else{
                int temp = a.front();
                a.pop_front();
                a.push_back(temp);
            }
            op++;
        }
        return op;
    }
};
