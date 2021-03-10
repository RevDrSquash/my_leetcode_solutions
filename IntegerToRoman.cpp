#include <array>

class Solution {
public:
    string intToRoman(int num) {
        std::array<int, 4> arDigits = splitDigits(num);
        
        string strNumerals = "";
        strNumerals += convertThousands(arDigits[3]);
        strNumerals += convertHundreds(arDigits[2]);
        strNumerals += convertTens(arDigits[1]);
        strNumerals += convertOnes(arDigits[0]);
        
        return strNumerals;
    }
    
    // ones at index 0, tens at index 1, etc.
    std::array<int, 4> splitDigits(int num) {
        std::array<int, 4> arResult;
        int nRemainder = num;
        
        arResult[3] = nRemainder / 1000;
        nRemainder -= arResult[3] * 1000;
        
        arResult[2] = nRemainder / 100;
        nRemainder -= arResult[2] * 100;
        
        arResult[1] = nRemainder / 10;
        nRemainder -= arResult[1] * 10;
        
        arResult[0] = nRemainder;
        
        return arResult;
    }
    
    string convertThousands(int num) {
        return convertDigit(num, "M", "?", "?");
    }
    
    string convertHundreds(int num) {
        return convertDigit(num, "C", "D", "M");
    }
    
    string convertTens(int num) {
        return convertDigit(num, "X", "L", "C");
    }
    
    string convertOnes(int num) {
        return convertDigit(num, "I", "V", "X");
    }
    
    string convertDigit(int num, string strOne, string strFive, string strTen) {
        switch(num) {
            case 9:
                return strOne + strTen;
            case 8:
                return strFive + strOne + strOne + strOne;
            case 7:
                return strFive + strOne + strOne;
            case 6:
                return strFive + strOne;
            case 5:
                return strFive;
            case 4:
                return strOne + strFive;
            case 3:
                return strOne + strOne + strOne;
            case 2:
                return strOne + strOne;
            case 1:
                return strOne;
            case 0:
                return "";
        }
        
        return "?";
    }
};
