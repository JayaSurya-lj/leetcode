class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibo;
        priority_queue<int> pq;
        if(1<=k){
            pq.push(1);
            pq.push(1);
        }
        fibo.push_back(1);
        fibo.push_back(1);
        int num = 0;
        while(num<=k){
            num = fibo[fibo.size()-1]+fibo[fibo.size()-2];
            fibo.push_back(num);
            pq.push(num);
        }
        int value = 0;
        int c = 0;
        while(!pq.empty() && value<=k){
            while(!pq.empty() && pq.top()>(k-value)) pq.pop();
            if(!pq.empty()){
                c++;
                cout<<pq.top()<<" ";
                value += pq.top();
                pq.pop();
            }
        }
        return c;

        
    }
};