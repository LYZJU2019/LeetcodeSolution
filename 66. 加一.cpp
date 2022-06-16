class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int start_pos = digits.size() - 1;
        int carry = ++digits[start_pos] / 10;
        for (int pos = start_pos - 1; pos >= 0 && carry; pos--) {
            digits[pos+1] %= 10;
            carry = ++digits[pos] / 10;
        }
        if (carry) {
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};