class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k<=numOnes) return k;
        else if(k>numOnes && k<=numOnes+numZeros) return numOnes;
        else{
            int negNum = k - (numZeros + numOnes);
            return numOnes - negNum;
        }
        
    }
};