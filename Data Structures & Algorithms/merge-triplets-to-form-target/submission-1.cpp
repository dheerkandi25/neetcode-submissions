class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>>valid;
        for(int i=0;i<triplets.size();i++) {
            if(!(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2])) {
                valid.push_back(triplets[i]);
            }
        }
        bool check1=false;
        bool check2=false;
        bool check3=false;
        for(int i=0;i<valid.size();i++) {
            if(valid[i][0]==target[0])
            check1=true;
            if(valid[i][1]==target[1])
            check2=true;
            if(valid[i][2]==target[2]) 
            check3=true;
        }
        if(check1 && check2 && check3) {
            return true;
        }
        return false;

        
    }
};
