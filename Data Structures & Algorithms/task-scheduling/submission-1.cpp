class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);
        for(char c : tasks)
            freq[c - 'A']++;

        priority_queue<int> pq;
        for(int f : freq)
            if(f > 0)
                pq.push(f);

        queue<pair<int,int>> q; // {time_available, freq}

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            // step 1: move ready tasks back to heap
            if(!q.empty() && q.front().first == time) {
                pq.push(q.front().second);
                q.pop();
            }

            if(!pq.empty()) {
                int f = pq.top();
                pq.pop();

                f--;

                if(f > 0) {
                    q.push({time + n + 1, f});
                }
            }
        }

        return time;
    }
};