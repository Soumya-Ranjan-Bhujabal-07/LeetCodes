#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < (int)s.size(); right++) {
            char ch = s[right];
            if (last_seen.count(ch) && last_seen[ch] >= left) {
                left = last_seen[ch] + 1;
            }
            last_seen[ch] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};