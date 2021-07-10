#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty() && popped.empty())
            return true;
        else if (pushed.empty() || popped.empty())
            return false;

        int sz = pushed.size();
        int nNextPush = 0, nNextPop = 0;

        stack<int> sData;
        while (nNextPop < sz) {
            while (sData.empty() || sData.top() != popped[nNextPop]) {
                if (nNextPush == sz)
                    break;
                sData.push(pushed[nNextPush]);

                nNextPush++;
            }

            if (sData.top() != popped[nNextPop])
                break;

            sData.pop();
            nNextPop++;
        }

        if(sData.empty() && nNextPop == sz)
            return true;
        else
            return false;
    }
};

