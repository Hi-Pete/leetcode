//
// 剑指 Offer 17. 打印从1到最大的n位数
//

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    void dft(string &num, int length, int index, vector<int> &res) {
        if (index == length -1) {
            int number = std::stoi(num);
            if (number != 0)
                res.push_back(number);

            return;
        }

        for (int i = 0; i < 10; ++i) {
            num[index +1] = '0' + i;
            dft(num, length, index +1, res);
        }
    }
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        string num(n, '0');

        for (int i = 0; i < 10; ++i) {
            num[0] = '0' + i;
            dft(num, n, 0, res);
        }

        return res;
    }
};

int main() {
    Solution solver;
    solver.printNumbers(2);

    return 0;
}