class Solution {
public:

struct Cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        // a = {enqueue, proc, idx}
        if (a[1] != b[1]) return a[1] > b[1]; // smaller proc first
        return a[2] > b[2];                   // tie: smaller idx first
    }
};

vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    for (int i = 0; i < n; i++) tasks[i].push_back(i); // add original index

    sort(tasks.begin(), tasks.end()); // sorts by enqueue, then proc, then idx

    priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;
    vector<int> ans;
    long long curTime = 0;
    int i = 0;

    while (i < n || !pq.empty()) {
        // If CPU idle, jump time to next task's enqueue
        if (pq.empty() && curTime < tasks[i][0]) {
            curTime = tasks[i][0];
        }

        // Push all tasks that have arrived by curTime
        while (i < n && tasks[i][0] <= curTime) {
            pq.push(tasks[i]);
            i++;
        }

        // Process the best task
        auto t = pq.top(); pq.pop();
        ans.push_back(t[2]);
        curTime += t[1];
    }

    return ans;
}
};