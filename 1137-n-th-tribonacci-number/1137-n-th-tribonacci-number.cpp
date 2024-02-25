class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        int ans;
        int first = 0;
        int second = 1;
        int third = 1;
        for(int i=0;i<=n-3;i++){
            ans = first + second + third;
            first = second;
            second = third;
            third = ans;
        }
        return ans;
    }
};