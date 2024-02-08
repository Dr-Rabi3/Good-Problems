class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> v(n);
        int a2 = 0,a3 = 0,a5 = 0;
        v[0]=1;
        for(int i=1;i<n;i++){
            v[i] = min({v[a2]*2,v[a3]*3,v[a5]*5});
            if(v[i] == v[a2]*2)a2++;
            if(v[i] == v[a3]*3)a3++;
            if(v[i] == v[a5]*5)a5++;
        }
        return v[n-1];
    }
};
