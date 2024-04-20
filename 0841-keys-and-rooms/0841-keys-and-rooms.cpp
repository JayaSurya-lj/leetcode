class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto neighbour: rooms[curr]){
                if(visited.find(neighbour)==visited.end()){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        cout<<visited.size();
        if(visited.size()==rooms.size()) return true;
        return false;
    
        
    }
};