#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_seen[256];
        memset(last_seen, -1, sizeof(last_seen));
        
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < (int)s.size(); right++) {
            unsigned char ch = s[right];
            if (last_seen[ch] >= left) {
                left = last_seen[ch] + 1;
            }
            last_seen[ch] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};