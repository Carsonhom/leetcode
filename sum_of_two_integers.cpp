class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0)
        {
            unsigned carry = (a & b) << 1; // calculate carry and left shift by 1
            a = a ^ b; // sum of bits a and b
            b = carry; 
        }
        return a;
    }
};
