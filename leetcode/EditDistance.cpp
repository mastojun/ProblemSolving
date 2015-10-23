/**
 * dp로 푸는 유명한 고전문제 라서 푸는데 고전함 (ㅠㅠ)
 * words1[i]와 words2[j]가 같으면
 *  words1[0..i-1]을 words2[0..j-1]로 만든것만큼의 비용
 *  words1[0..i-1]을 words2[0..j]로 만든 비용 + 1 (words[j]제거)
 *  words1[0..1]을 words2[0..j-1]로 만든 비용 + 1 (words[j]추가)
 *  중 최솟값
 * words1[i]와 words2[j]가 다르면
 *  위 조건중 첫번째에 + 1 (words1[i]를 words2[j]로 대체) 중 최솟값
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(2, vector<int>(word1.length() + 1, 0));

        for (int i = 1; i <= word1.length(); i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word2.length(); i++) {
            dp[i%2][0] = i;
            for (int j = 1; j <= word1.length(); j++) {
                dp[i%2][j] = min(dp[(i+1)%2][j] + 1, dp[i%2][j-1] + 1);

                if(word2[i - 1] == word1[j - 1]) {
                    dp[i%2][j] = min(dp[i%2][j], dp[(i+1)%2][j-1]);
                } else {
                    dp[i%2][j] = min(dp[i%2][j], dp[(i+1)%2][j-1] + 1);
                }
            }
        }

        return dp[word2.length()%2][word1.length()];
    }
};

