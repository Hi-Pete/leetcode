//
// Created by hipete on 21-4-25.
//

#include <ctgmath>

class Solution {
    double pow_recur(double base, unsigned int exp){
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base;

        double res = pow_recur(base, exp/2);

        res *= res;
        if (exp %2 == 1)
            res *= base;

        return res;
    }
public:
    double myPow(double x, int n) {
        if (std::fabs(x-0.0) < 0.000000001 && n < 0)
            return 0.0;


        unsigned int absExp;
        if (n < 0)
            absExp = (unsigned int)(-(long long)n);
        else
            absExp = (unsigned int)n;


        double res = pow_recur(x, absExp);

        if (n < 0)
            res = 1.0/res;

        return res;
    }
};