class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int n = s.size();
        
        auto value = [](char c) {
            switch(c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
            }
            return 0;
        };
        
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && value(s[i]) < value(s[i + 1])) {
                total += value(s[i + 1]) - value(s[i]);
                i++; 
            } else {
                total += value(s[i]);
            }
        }
        
        return total;
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        int n = s.size();
        int number = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp[s[i]] < mp[s[i + 1]]) {
                number -= mp[s[i]];
            } else {
                number += mp[s[i]];
            }
        }
        return number;

    }
};
