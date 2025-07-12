#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
		vector<pair<int, int>> ms;
		for (auto &m: meetings)
			ms.push_back(make_pair(m[0], m[1]));
		sort(ms.begin(), ms.end());

		priority_queue<pair<long long, int>> busy_rooms;  // (-end_time, -room_id)
		priority_queue<int> empty_rooms; // -room_id
		for (int i = 0; i < n; ++i)
			empty_rooms.push(-i);

		vector<int> cnt;
		cnt.resize(n);

    	for (auto &m: ms) {
    		long long start_time = m.first, duration = m.second - m.first;
    		while (!busy_rooms.empty()) {
    			int last_end_time = -busy_rooms.top().first, room_id = -busy_rooms.top().second;
    			if (last_end_time <= start_time) {
					empty_rooms.push(-room_id);
					busy_rooms.pop();
				} else break;
			}
			
			int room_id = 0;
			if (empty_rooms.empty()) {
				start_time = -busy_rooms.top().first;
				room_id = -busy_rooms.top().second;
				busy_rooms.pop();
			} else {
				room_id = -empty_rooms.top();
				empty_rooms.pop();
			}
			
    		++cnt[room_id];
    		busy_rooms.push(make_pair(-(start_time + duration), -room_id));
		}
		int max_ind = 0;
		for (int i = 0; i < n; ++i)
			if (cnt[i] > cnt[max_ind])
				max_ind = i;
        return max_ind;
    }
} s;
const int MaxN = 100000 + 10;
int n, m;
vector<vector<int>> meetings;
int main() {
	cin >> n >> m;
	meetings.resize(m);
	for (int i = 0; i < m; ++i) {
		meetings[i].resize(2);
		cin >> meetings[i][0] >> meetings[i][1];
	}
	cout << s.mostBooked(n, meetings);
	return 0;
}
/*
2 4 0 10 1 5 2 7 3 4
*/
