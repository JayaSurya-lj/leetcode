bool cmp(pair<int,int>& p1,pair<int,int>& p2){
    return p1.second > p2.second;
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> arr;
        for(int i=0;i<boxTypes.size();i++){
            arr.push_back({boxTypes[i][0],boxTypes[i][1]});
        }
        sort(arr.begin(),arr.end(),cmp);
        int units = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i].first<=truckSize){
                units += (arr[i].first * arr[i].second);
                truckSize -= arr[i].first;
            }
            else{
                int boxes = arr[i].first;
                int unit = arr[i].second;
                while(boxes && truckSize){
                    units += unit;
                    boxes--;
                    truckSize--;
                }
                break;

            }
        }
        return units;
        return 0;
        
    }
};