class Solution {
public:
    int findComplement(int num) {
        vector<int> bits;

        int number = num;
        while (number) {
            int x = number % 2 ? 0 : 1;
            bits.push_back(x);
            number = number / 2;
        }

        int ans = 0;
        for (int i = 0; i < bits.size(); i++) {
            ans += bits[i] * pow(2, i);
        }

        return ans;
    }
};