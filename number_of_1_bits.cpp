class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0)
        {
            if (n & 1) // check if least significant bit == 1
                count++;
            n >>= 1; // shift to the right
        }
        return count;
    }
};
