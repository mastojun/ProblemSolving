class Solution{
	public:
		string addBinary(string a, string b) {
			string result;

			int aLen = a.length();
			int bLen = b.length();
			int carry = 0;
			int rLen = 0;

			while(aLen > 0 || bLen > 0) {
				result.push_back(carry);
				if(aLen > 0) result[rLen] += a[aLen - 1] - '0';
				if(bLen > 0) result[rLen] += b[bLen - 1] - '0';
				carry = result[rLen] > 1 ? 1 : 0;
				result[rLen] %= 2;
				result[rLen] += '0';

				rLen++;
				aLen--;
				bLen--;
			}
			if(carry == 1) result.push_back('1');

			reverse(result.begin(), result.end());

			return result;
		}
};

