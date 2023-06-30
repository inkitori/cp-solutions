class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        begin = 0
        end = 0
        seen = {}
        long_len = 0
        
        for i in range(len(s)):
            seen[s[i]] = i
            end += 1
            try:
                if s[end] in seen:
                    if seen[s[end]] >= begin:
                        begin = seen[s[end]] + 1
            except IndexError:
                end -= 1
                
            cur_len = end - begin + 1
            if cur_len > long_len:
                long_len = cur_len
            print(cur_len)
            
        return long_len
        