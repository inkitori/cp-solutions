class Solution:
    def defangIPaddr(self, address: str) -> str:
        defanged = ""
        
        for c in address:
            if c == '.':
                defanged += "[.]"
            else:
                defanged += c
        return defanged