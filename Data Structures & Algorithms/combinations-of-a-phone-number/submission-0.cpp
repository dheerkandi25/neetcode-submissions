class Solution {
public:
    vector<string>ans;
    vector<string>letters={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void buildCombination(string digits,int i,string &curr) {
        if(i==digits.length()) {
            ans.push_back(curr);
            return;
        }
        string temp=letters[digits[i]-'0'-2];
        for(int k=0;k<temp.length();k++) {
            curr.push_back(temp[k]);
            buildCombination(digits,i+1,curr);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) {
            return ans;
        }
        string curr="";
        buildCombination(digits,0,curr);
        return ans;

        
    }
};
