// 20. 有效的括号
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合
// 左括号必须以正确的顺序闭合
// 注意空字符串可被认为是有效字符串
//

#include <string>
#include <stack>
#include <unordered_map>

class Solution {
  public:
    bool isValid(std::string s) {
        std::stack<char> parsed;        // 解析栈
        for (int i = 0; i < s.length(); ++i) {  // 遍历输入字符串并解
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')  // 如果是前括号
                    parsed.push(s[i]);                      // 入栈
            else {                      // 否则是后括号
                if (parsed.empty())     // 若解析栈为空
                    return false;       // 返回结果：无效
                char c = parsed.top();  // 取栈顶存入空栈
                if ((s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') || (s[i] == ')' && c == '('))
                    parsed.pop();   // 若后括号和栈顶元素（最近入栈的前括号）对应，则出栈
                else
                    return false;   // 不对应则返回结果：无效
            }
        }
        return parsed.empty();  // 解析输入完成后，若解析栈为空则返回结果：有效
    }

    bool isValid_map(std::string s) {
        std::unordered_map<char,int> parentheses_map{{'(',1},{'[',2},{'{',3},
                                                     {')',4},{']',5},{'}',6}};
        std::stack<char> parsed;
        for (char c:s) {
            int flag = parentheses_map[c];

            if(flag>=1 && flag<=3)
                parsed.push(c);     // 如果是左括号就进栈
            else if(!parsed.empty() && (parentheses_map[parsed.top()]==flag-3) )
                parsed.pop();       // 弹出栈顶元素
            else
                return false;
        }
        return parsed.empty();
    }
};
