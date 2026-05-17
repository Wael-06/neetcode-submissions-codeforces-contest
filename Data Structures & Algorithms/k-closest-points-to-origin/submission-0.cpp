class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> h;//(distance , point)

        for(auto& p : points) {

            int x = p[0];
            int y = p[1];

            int dist = x*x + y*y;//no sqrt as it is extra work for nothing 

            h.push({dist, p});

            if(h.size() > k) {
                h.pop();
            }
        }

        vector<vector<int>> ans;

        while(!h.empty()) {
            ans.push_back(h.top().second);
            h.pop();
        }

        return ans;
    }
};