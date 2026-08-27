class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        int maxf=INT_MIN;
        for(int i=0;i<tasks.size();i++) {
            freq[tasks[i]]++;
            if(freq[tasks[i]]>maxf) {
                maxf=freq[tasks[i]];
            }
        }
            int count=0;
            for(auto it:freq) {
                if(it.second==maxf) {
                    count++;
                }
            }


        
        return max((int)tasks.size(),(maxf-1)*(n+1)+count);

        
    }
};
