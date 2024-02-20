bool cmp(int& a,int& b){
    return a>b;
}
class Solution {
public:
    int minimumSum(int num) {
        int temp = num;
        vector<int> v;
        while(temp>0){
            v.push_back(temp%10);
            temp /= 10;
        }
        sort(v.begin(),v.end(),cmp);
        int a = v[3];
        int b = v[2];
        a = (a*10) + v[1];
        b = (b*10) + v[0];
        return a+b;
    }
};