class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(int i=0;i<bills.size();i++) {
            if(bills[i]==5) {
                five++;
            }
            else if(bills[i]==10) {
                ten++;
                if(five==0) {
                    return false;
                }
                five--;
                
            }
            else if(bills[i]==20) {
                if(five==0 || (ten==0 && five<3)) {
                    return false;
                }
                else if(ten!=0)
                {
                     five--;
                    ten--;
                }
                else {
                    five-=3;
                }
               
            }
        }
        return true;
        
    }
};