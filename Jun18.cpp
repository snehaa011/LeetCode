class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector< pair<int,int> > task;
        int n=profit.size();
        for (int i=0; i<n; i++){
            task.push_back({difficulty[i], profit[i]});
        }
        sort(task.begin(), task.end());
        int mprofit=0;
        for (auto ability : worker){
            int i=0, m=0;
            while (i<n && task[i].first<=ability){
                if (m<task[i].second){
                    m=task[i].second;
                }
                i++;
            }
            mprofit+=m;
        }
        return mprofit;
    }
};
