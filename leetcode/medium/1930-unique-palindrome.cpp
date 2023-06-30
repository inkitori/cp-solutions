class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<int> minIdx(26, 100001);
        vector<int> maxIdx(26, -1);
        
        bool palindromes[26][26][26] = {};
        
        for (int i = 0; i < s.size(); ++i) {
            int charInt = s[i] - 'a';
            minIdx[charInt] = min(minIdx[charInt], i);
            
            if (minIdx[charInt] < i) { // palindrome
                for (int j = 0; j < 26; ++j) {
                    if (maxIdx[j] > minIdx[charInt] && !palindromes[charInt][j][charInt]) {
                        palindromes[charInt][j][charInt] = true;
                        ++ans;
                    }
                }
            }
            
            
            
            maxIdx[charInt] = max(maxIdx[charInt], i);
        }
        
        return ans;
    }
};