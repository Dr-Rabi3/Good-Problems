//  https://leetcode.com/problems/find-the-winner-of-the-circular-game/?envType=study-plan&id=data-structure-ii

class Solution {
public:
    int solve(int n,int k){
        if(n==1) return 0;
        return (solve(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return solve(n,k) + 1;
    }
};


class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            int x=k;
            while(x>1){
                int r=q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
};
