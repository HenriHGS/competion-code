
// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ans;
        ans.push_back(1);
        for(int i = 2; i <= N; i ++ ) {
            int l = 0, r = i - 2;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(compare(ans[mid],i)) l = mid;
                else r = mid - 1;
            }
            ans.push_back(i);
            for(int j = ans.size() - 2; j > r; j -- ) swap(ans[j+1], ans[j]);
            if(!compare(ans[r],i)) swap(ans[r], ans[r+1]);
        }
        return ans;
    }
};