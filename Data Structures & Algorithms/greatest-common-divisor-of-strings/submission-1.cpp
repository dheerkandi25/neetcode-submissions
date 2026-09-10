class Solution {
public:
    bool isDivisor(int i,string str1,string str2) {
        if(!(str1.length()%i==0 && str2.length()%i==0)){
            return false;
        }
        string modstr1="";
        for(int t=0;t<str1.length()/i;t++) {
            modstr1+=str1.substr(0,i);
        }
        if(modstr1!=str1){
            return false;
        }
        string modstr2="";
        for(int t=0;t<str2.length()/i;t++) {
            modstr2+=str1.substr(0,i);
        }
        if(modstr2!=str2) {
            return false;
        }
        return true;

    }
    string gcdOfStrings(string str1, string str2) {
        for(int i=min(str1.size(),str2.size());i>=1;i--) {
            if(isDivisor(i,str1,str2)) {
                return str1.substr(0,i);
            }
        }
        return "";
        
    }
};