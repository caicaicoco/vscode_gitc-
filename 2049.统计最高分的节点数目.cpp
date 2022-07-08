/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
        long maxScore=0;
        int ant=0;
        int n;
        vector<vector<int>> children;
        int dfs(int node){
            long score=1;
            int size=n-1;
            for(int c:children[node]){
                int t=dfs(c);
                score*=t;
                size-=t;
            }
            if(node!=0){
                score*=size;
            }
            if(score==maxScore){
                ant++;
            }
            else if(score>maxScore){
                maxScore=score;
                ant=1;
            }
            return n-size;
        }
    int countHighestScoreNodes(vector<int>& parents) {
       this->n=parents.size();
       this->children=vector<vector<int>>(n);
       for(int i=0;i<n;i++){
           int p=parents[i];
           if(p!=-1){
               children[p].emplace_back(i);
           }
       }
      dfs(0);  
      return ant;
    }
};
// @lc code=end

