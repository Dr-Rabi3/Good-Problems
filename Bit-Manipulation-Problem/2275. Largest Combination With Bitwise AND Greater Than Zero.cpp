// we need to count integerts that share the same bit. Bitwise AND of those integers will be positive.
/**
We want AND of some numbers to be > 0.
Now when we want to do AND of some bits, the result will be 0 even if any one of those bits is 0.

Ques: When can we get a result 0 when we do AND of two numbers?
Ans: If all bits at same pos are opposite or both are 0, e.g - 1000 & 0110 = 0
Conclusion: Thus, to get AND result non zero there must be a place i where bit is 1 in both numbers.

And this same logic applies when we want to AND more than two numbers.
So in this problem, we want to check how many numbers have 1 at the same position.

Like in sample test case, [16,17,71,62,12,24,14]

16 = 0 0 1 0 0 0 0
17 = 0 0 1 0 0 0 1
71 = 1 0 0 0 1 1 1
62 = 0 1 1 1 1 1 0
12 = 0 0 0 1 1 0 0
24 = 0 0 1 1 0 0 0
14 = 0 0 0 1 1 1 0

We can say that if we AND, 71, 62, 12, and 14 then in the final result 2nd bit will be 1
Thus this result will surely be greater than 0.
**/
class Solution {
public:
       int largestCombination(vector<int>& A) {
        int res = 0, cur = 0;
        for (int i = 0; i < 30; ++i, cur = 0)
            for (int a: A)
                res = max(res, cur += a >> i & 1);
        return res;    
    }
};

//------------------------------------------------
int largestCombination(vector<int>& cs) {
    int cnt[24] = {};
    for (auto n : cs)
        transform(begin(cnt), end(cnt), begin(bitset<24>(n).to_string()), begin(cnt), [](int s, char ch){ return s + (ch == '1'); });
    return *max_element(begin(cnt), end(cnt));
}
