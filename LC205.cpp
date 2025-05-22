// Time complexity O(n)
// Space complexity O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> s_map;
        unordered_set<char> t_set;
        
        for (int i = 0; i < s.length(); i++) {    
            char ch_s = s[i];
            char ch_t = t[i];
            auto it = s_map.find(ch_s);
            if (it != s_map.end()) {
                if (it->second != ch_t) {
                    return false;
                }
            } else {
                if (t_set.find(ch_t) != t_set.end()) {
                    return false;
                }
                s_map[ch_s] = ch_t;
                t_set.insert(ch_t);
            }
        }

        return true;
    }
};