/**
 * 풀이
 * 입력된 문자열에서 insignificant 단어들을 모두 제거 한 후에
 * 각 단어에 하나씩의 축약어가 있는지를 검사함
 *
 * 축약어 인덱스(fi)와 단어 인덱스(idx)가 상태공간의 크기이며, 조합이 많이 발생해서 메모이제이션으로 품.
 * 축약어가 한 단어에 하나이상 포함되었는지를 판단하는 부분으로 인해 코드가 지저분함.
 *
 * 회고
 * 단어리스트로 바꾸고 나서 처리를 했으면 더 간단했을 텐데, 문자열을 그대로 사용해서 코드가 지저분함 (...)
 * 심지어, 초반에는 ignore도 solve함수 내에서 처리해서 오답을 찾는데 더 오래걸림.
 * 처음 함수를 작성할 때 idx값이 각 단어으 처음 위치만 올 수 있다고 생각을 해서 사고가 꼬여버림 (ㅠㅠ)
 */

#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int n;
char insignificantWords[100][200];
int wordLength;
char words[200];
int dp[200][200];
int solve(int fi, int idx) {
	if (idx >= wordLength) {
		return words[fi] == 0;
	}
	if (words[fi] == 0) {
		for (int i = idx; words[i] && words[i] != ' '; i++) {
			if (i == wordLength - 1) return words[idx - 1] != 0;
		}
		return 0;
	}
	int& ret = dp[fi][idx];
	if (ret != -1) return ret;

	ret = 0;
	int nextIdx = 0;
	for (int i = idx;; i++) {
		if (words[i] == 0 || words[i] == ' ') {
			words[i] = 0;
			nextIdx = i + 1;
			break;
		}
	}
	bool isFirstCharacter = words[idx - 1] == 0;

	for (int i = idx; words[i]; i++) {
		if (tolower(words[i]) == tolower(words[fi])) {
			ret += solve(fi + 1, i + 1);
		}
	}
	if (!isFirstCharacter) ret += solve(fi, nextIdx);

	return ret;
}

int solve() {
	int idx = 0;
	while (words[idx] != ' ') idx++;
	words[idx] = 0;

	return solve(0, idx + 1);
}

void removeIgnore() {
	char nextWords[200];
	int idx = 0;

	char each[200] = { 0 };
	int eachIdx = 0;

	int wordsLength = strlen(words);
	for (int i = 0; i <= wordsLength; i++) {
		if (words[i] && words[i] != ' ') {
			each[eachIdx++] = words[i];
			each[eachIdx] = 0;
		}
		else {
			bool ignore = false;
			for (int j = 0; j < n; j++) {
				if (strcmp(insignificantWords[j], each) == 0) {
					ignore = true;
					break;
				}
			}
			if (!ignore) {
				if (idx > 0) {
					sprintf(nextWords + idx, " ");
					idx++;
				}
				sprintf(nextWords + idx, "%s", each);
				idx += eachIdx;
			}
			eachIdx = 0;
		}
	}
	strcpy(words, nextWords);
}

int main() {
	while (scanf("%d\n", &n)) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			scanf("%s\n", insignificantWords[i]);
		}

		while (gets(words)) {
			if (strcmp(words, "LAST CASE") == 0) {
				break;
			}

			removeIgnore();

			wordLength = strlen(words);
			memset(dp, -1, sizeof(dp));

			int result = solve();
			if (result > 0) {
				printf("%s can be formed in %d ways\n", words, result);
			}
			else {
				printf("%s is not a valid abbreviation\n", words);
			}
		}
	}
	return 0;
}

