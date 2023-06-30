class Solution {
public:
    bool isValid(string s) {
        stack<char> idk;
        
        for (char c : s) {
            if (c == '{' || c == '(' || c == '[') idk.push(c);
            else if (idk.size() > 0) {
                if (c == '}' && idk.top() != '{') return false;
                if (c == ')' && idk.top() != '(') return false;
                if (c == ']' && idk.top() != '[') return false;
                
                idk.pop();
            }
            else return false;

        }
        if (idk.size() == 0) return true;
        return false;
    }
};