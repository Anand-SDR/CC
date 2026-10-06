class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        for (int unique = 1; unique <= 26; unique++) {

            vector<int> freq(26, 0);

            int left = 0, right = 0;
            int uniqueCount = 0;
            int atLeastK = 0;

            while (right < s.length()) {

                int x = s[right] - 'a';

                if (freq[x] == 0)
                    uniqueCount++;

                freq[x]++;

                if (freq[x] == k)
                    atLeastK++;

                right++;

                while (uniqueCount > unique) {

                    int y = s[left] - 'a';

                    if (freq[y] == k)
                        atLeastK--;

                    freq[y]--;

                    if (freq[y] == 0)
                        uniqueCount--;

                    left++;
                }

                if (uniqueCount == unique && atLeastK == unique)
                    ans = max(ans, right - left);
            }
        }

        return ans;
    }
};