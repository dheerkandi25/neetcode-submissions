class Solution {
public:
   
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for(auto &it : mp) {
            maxHeap.push({it.second, it.first});
        }

        string ans = "";

        pair<int, char> prev = {0, '#'};

        while(!maxHeap.empty()) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            ans.push_back(curr.second);
            curr.first--;

            // Put previous character back only after
            // choosing a different character.
            if(prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = curr;
        }

        if(ans.length() != s.length()) {
            return "";
        }

        return ans;
        
    }
};