/*
 * hashmap 으로 하는것(100ms)보다 배열로 하는게(10ms) leetcode상에서 10배 정도 빠르다고 함
 *
 */
class Solution {
public:
    string minWindow(string s, string t) {
        bool present[128];
        int counter[128] = {0};
        int uniqueSize = 0;
        for(int i = 0; i < 127; i++) {
            present[i] = false;
        }
        for(char c : t) {
            if(!present[c]) {
                uniqueSize++;
                present[c] = true;
            }
            counter[c]++;
        }

        int result = s.length() + 1;
        int start = 0;
        int end = 0;
        for(int l = 0, r = 0; r < s.length(); r++) {
            if(present[s[r]]) {
                counter[s[r]]--;
                if(counter[s[r]] == 0) {
                    uniqueSize--;
                }
            }
            while(uniqueSize == 0) {
                if(result > r - l + 1) {
                    result = r - l + 1;
                    start = l;
                    end = r + 1;
                }

                if(present[s[l]]) {
                    counter[s[l]]++;
                    if(counter[s[l]] > 0) {
                        uniqueSize++;
                    }
                }
                l++;
                if(l > r) break;
            }
        }

        return s.substr(start, end - start);
    }
};

