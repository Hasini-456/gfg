// User function Template for C++

class Solution {
  public:
    bool wifiRange(int N, string S, int X) {
        // code here
        int i=0;
        int j = -1;
        queue<int> q;
        while(i < N){
            if(S[i] == '0') {
                if(i > j) q.push(i);
            }
            else{
                if(!q.empty() && q.front() < i-X) return false;
                else{
                    while(!q.empty()) q.pop();
                }
                j = i+X;
            }
            i++;
        }
        return q.empty();
    }
};
