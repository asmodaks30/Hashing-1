// Time complexity O(n)
// Space complexity O(n)

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::istringstream iss(s);
        std::string word;
        std::vector<std::string> words;
        while (iss >> word) {
            words.push_back(word);
        }
        
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> map;
        unordered_set<string> set;
        
        for (int i = 0; i < pattern.length(); i++) {    
            char ch = pattern[i];
            const auto& word = words[i];
            auto it = map.find(ch);
            if (it != map.end()) {
                if (it->second != word) {
                    return false;
                }
            } else {
                if (set.find(word) != set.end()) {
                    return false;
                }
                map[ch] = word;
                set.insert(word);
            }
        }

        return true;
    }
};