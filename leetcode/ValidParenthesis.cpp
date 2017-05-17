//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    stack <char> open;
    bool isValid(string s) {
     
        for(int i = 0; i < s.length(); i++)
        { 
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    open.push(s[i]);
                    break;
                case ')':
                    if((!open.empty()) && (open.top() == '('))
                    {
                       open.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '}':
                    if((!open.empty()) && (open.top() == '{'))
                    {
                       open.pop();
                    }
                    else
                    {
                        return false;
                    } 
                    break;
                case ']':
                    if((!open.empty()) && (open.top() == '['))
                    {
                       open.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                
            }
        }
       
        return open.empty();
    }
};