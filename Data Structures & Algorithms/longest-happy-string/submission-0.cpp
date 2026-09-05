class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)
        pq.push({a,'a'});
        if(b>0)
        pq.push({b,'b'});
        if(c>0)
        pq.push({c,'c'});
        bool pause=false;
        string ans="";
        pair<int,char>prev={0,'d'};
        while(!pq.empty()) {
            auto it=pq.top();
            pq.pop();
            
            ans.push_back(it.second);
            it.first--;
            if(ans.size()>=2 && ans.back()==ans[ans.size()-2]){
                prev=it;
            }
            else {
                if(it.first>0)
                pq.push(it);
                if(prev.first>0)
                {
                    pq.push(prev);
                    prev={0,'d'};
                }
            }

        }
        return ans;
        

        
    }
};