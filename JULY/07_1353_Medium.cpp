/*
1353. Maximum Number of Events That Can Be Attended

You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.


Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105
*/

// Naive but mine solution: 

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1]; // sort by second element
             });
        int count = 0;
        int n = events.size();
        vector<bool> canAttend(1e5 + 10, 1);
        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            if (canAttend[start] == true) {
                count++;
                canAttend[start] = false;
            } else {
                while (start <= end) {
                    if (canAttend[start] == true) {
                        canAttend[start] = false;
                        count++;
                        break;
                    }
                    start++;
                }
            }
        }
        return count;
    }
};

// this solution gives TLE


// optimized DSU solution: 

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int maxDay = 0;
        for (auto& e : events)
            maxDay = max(maxDay, e[1]);

        parent.resize(maxDay + 2);
        for (int i = 0; i <= maxDay + 1; i++)
            parent[i] = i;

        int count = 0;
        for (auto& e : events) {
            int day = find(e[0]);
            if (day <= e[1]) {
                count++;
                parent[day] = find(day + 1);
            }
        }
        return count;
    }
};

// self note : you HAVE TO STUDY DSU dude!!!
