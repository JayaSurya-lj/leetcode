class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i = 0;
        int bricksUsed = 0;
        for(;i<heights.size()-1;i++){
            if(heights[i] >= heights[i+1]){
                continue;
            }
            int heightDiff = heights[i+1] - heights[i];
            if(heightDiff + bricksUsed <= bricks){ // if bricks available
                bricksUsed += heightDiff;
                pq.push(heightDiff); // push the current jump up through bricks
            }
            else if(ladders>0){
                if(!pq.empty() && pq.top()>heightDiff){
                    bricksUsed = bricksUsed - pq.top() + heightDiff;
                    pq.pop();
                    pq.push(heightDiff);
                }
                ladders--;
            }
            else
            {
                break;
            }
        }
        return i;
    }
};