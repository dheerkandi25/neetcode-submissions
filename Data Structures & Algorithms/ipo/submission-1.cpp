class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;
        int currCapital=w;
        while(k>0) {
            for(int i=0;i<capital.size();i++) {
                if(capital[i]<=currCapital && capital[i]!=-1) {
                    pq.push(profits[i]);
                    capital[i]=-1;
                }
            }
              if(pq.empty()) {
                break;
            }
            k--;
            currCapital+=pq.top();
            pq.pop();
        }
        return currCapital;
    }
};