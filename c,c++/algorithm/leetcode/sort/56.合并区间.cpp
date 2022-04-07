/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 * 
 * 这里的bool cmp函数，要用静态的，否则会有问题？？？？
 */

// @lc code=start
class Solution {
public:
    bool cmp(vector<int>a, vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l, r;
        vector<vector<int>>res;
        vector<vector<int>>& seg = intervals;
       // sort(seg.begin(),seg.end(),Solution().cmp);
        sort(seg.begin(),seg.end(),[](vector<int>a, vector<int> b)->bool{
             return a[0]<b[0];
         });
        for(int i = 0; i < seg.size(); i ++ ){
            int j = i;
            l = seg[i][0], r = seg[i][1];
            while(j < intervals.size() && seg[j][0] <= r){
                r = max(r,seg[j][1]);
                j++;
            }
            i = j-1;
            vector<int>a{l,r};
            res.push_back(a);
        }
        return res;
    }
};
// @lc code=end

