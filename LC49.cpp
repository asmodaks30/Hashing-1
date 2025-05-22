// Time Complexity O(nk)
// Space Complexity O(n)
class Solution {
    double primeProduct(const string& str) {
        const int primeCount = 26;
        int primes[primeCount] = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
            73, 79, 83, 89, 97, 101
        };

        double product = 1.0;
        for (char ch : str) {
            product *= primes[ch-'a'];
        }
        return product;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<double, vector<string>> groups;
        for (const auto& str : strs) {
            double hash = primeProduct(str);
            if (groups.find(hash) != groups.end()) {
                groups[hash].push_back(str);
            } else {
                groups[hash] = {str};
            }
        }
        vector<vector<string>> rv;
        for (const auto& [hash, group] : groups) {
            rv.push_back(group);
        }
        return rv;
    }
};