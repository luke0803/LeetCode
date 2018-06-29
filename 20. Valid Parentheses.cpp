class Solution {
public:
    bool isValid(string s) {
   
    stack<char> stk;
    stk.push('#');
    char top;
        for(char c : s)
        //for(int i=0; i < s.size(); i++)
        {
            top = stk.top();
                 if(top == '(' && c == ')') stk.pop(); 
            else if(top == '[' && c == ']') stk.pop(); 
            else if(top == '{' && c == '}') stk.pop();
            else stk.push(c);
        }
        top = stk.top();
        return top == '#';
    }
};
