class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto &it: details) {
            string num = "";
            num += it[11];
            num += it[12];

            int num_ = stoi(num);
            if(num_ > 60) count++;
        }

        return count;
    }
};