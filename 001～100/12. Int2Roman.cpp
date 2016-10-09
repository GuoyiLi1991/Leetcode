class Solution {
    string digitToRoman(int digit, char ten, char five, char one) {
        string result;
        if (digit == 9)
        {
            result += one;
            result += ten;
        }
        else if (digit >=5) {
            result += five;
            digit -= 5;
            while (digit--)
                result += one;
        }
        else if (digit == 4) 
        {
            result += one;
            result += five;
        }
        else {
            while (digit--)
                result += one;
        }

        /* in the form of switch:
        switch (digit) {
            case 9:
                result += one;
                result += ten;
                break;
            case 4:
                result += one;
                result += five;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                result += five;
                digit -= 5;
            default:
                while (digit--)
                    result += one;
        }
        */
        return result;
    }
public:
    string intToRoman(int num) {
        int digit_1000 = num/1000; //thousand
        int digit_100 = (num % 1000)/100; //hundred
        int digit_10 = (num % 100) / 10; //ten
        int digit_1 = num % 10; //one
        string result;
        result = digitToRoman(digit_1000, 'M', 'M', 'M') + digitToRoman(digit_100, 'M', 'D', 'C')
            + digitToRoman(digit_10, 'C', 'L', 'X') + digitToRoman(digit_1, 'X', 'V', 'I');
        

        return result;
    }
};