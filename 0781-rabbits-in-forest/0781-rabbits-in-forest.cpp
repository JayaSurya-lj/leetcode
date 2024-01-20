class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        long long int sum = 0;
        for(int i=0;i<answers.size();i++){
            if(answers[i]==0) sum++;
            else
            mp[answers[i]]++;
        }
        for(auto p:mp){
            int key = p.first;
            int freq = p.second;
            while(freq>key+1){
                sum += key+1;
                freq -= key+1;
            }
            if(freq!=0){
                sum += key+1;
            }
        }
        return sum;
        
    }
};