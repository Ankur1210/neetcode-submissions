class Solution {
public:
    bool isAnagram(string s, string t) {
        // Method 1
        if(s.size()!=t.size())
            return false;

        vector<int> ans(26);

        for(int i=0;s[i]!='\0';i++){
            ans[s[i]-'a']++;
        }

        for(int i=0;t[i]!='\0';i++){
            if(ans[t[i]-'a']<=0)
                return false;
            else
                ans[t[i]-'a']--;
        }

        return true;
        
    }
};
