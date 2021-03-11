// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if((dividend < 0) != (divisor < 0))
        {
            sign = -1;
        }
        
        unsigned int uDividend = abs(dividend);
        unsigned int uDivisor = abs(divisor);
        
        int nDividendSize = findMSB(uDividend);
        
        unsigned int quotient = 0;
        unsigned int remainder = 0;
        
        for(int i = (nDividendSize - 1); i >= 0; i--)
        {
            remainder = remainder << 1;
            remainder += ((uDividend >> i) & 1);
            
            if(remainder >= uDivisor)
            {
                remainder = remainder - uDivisor;
                quotient = quotient | (1 << i);
            }
        }
        
        if(sign > 0 && quotient >= 2147483648)
            return 2147483647;
        else
            return sign * quotient;
    }
    
    int findMSB(unsigned int num) {
        int nMSB = 0;
        while (num > 0)
        {
            num = num >> 1;
            nMSB++;
        }
        
        return nMSB;
    }
};
