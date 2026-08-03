class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left=0;
        int right=1;
        int maxAns=1;
        int curr=1;
        int flag=-1;
        while(right<arr.size()) {
            if(arr[right]==arr[right-1]) {
                left=right;
                flag=-1;
            }
            else if(arr[right]<arr[right-1] ) {
                if(!(flag==-1 || flag==1)){
                    left=right-1;
                }
                flag=0;
            }
            else if(arr[right]>arr[right-1]) {
                if(!(flag==-1 || flag==0)) {
                    left=right-1;
                    
                }
                flag=1;
            }
            curr=right-left+1;
            right++;
            maxAns=max(maxAns,curr);
        }
        return maxAns;
        
    }
};