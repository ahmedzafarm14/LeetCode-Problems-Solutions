// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_set<char> seen;

        while (right < n) {
            if (seen.find(s[right]) == seen.end()) {
                seen.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                seen.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};
