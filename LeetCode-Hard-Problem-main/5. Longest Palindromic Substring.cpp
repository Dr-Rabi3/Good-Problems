class Solution {
public:
    int Len(int st,int en,string s){
        while(st >= 0 && en < s.size() && s[st] == s[en] )st--,en++;
        return en - st - 1;
    }
    string longestPalindrome(string s) {
        int st = 0,en = 0;
        for(int i=0;i<s.size();i++){
            int len1 = Len(i, i, s);
            int len2 = Len(i, i + 1, s);
            int len = max(len1,len2);
            if(en < len){
                st = i - (len - 1) / 2;
                en = len;
            }
        }
        // cout << st << ' ' << en;
        return s.substr(st,en);
    }
};
