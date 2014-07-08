class Solution {
	public:
		int maxPoints(vector<Point> &points) {
			int result = 0;
			for(int i = 0; i < points.size(); i++) {
				int sameMe = 1;
				int loopResult = 0;
				map<double, int> counter;
				for(int j = i + 1; j < points.size(); j++) {
					double a = 0;
					if(points[i].x == points[j].x) {
						if(points[i].y == points[j].y) {
							sameMe++;
							continue;
						}else {
							a = numeric_limits<double>::max();
						}
					}else{
						a = (points[i].y - points[j].y) * 1./(points[i].x - points[j].x);
						a = ((long long)(a*10000000L)) / 100000000.;
					}

					counter[a]++;
					loopResult = max(loopResult, counter[a]);
				}
				result = max(result, loopResult + sameMe);
			}

			return result;
		}
};
