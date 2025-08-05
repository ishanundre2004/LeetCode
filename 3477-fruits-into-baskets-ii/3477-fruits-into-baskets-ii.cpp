class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt =0;
        for(int f = 0; f < fruits.size(); f++){
            for(int b = 0 ; b < baskets.size(); b++){
                if(fruits[f] <= baskets[b]){
                    cnt++;
                    baskets[b] = -1;
                    break;
                }
            }
        }
        return fruits.size() - cnt;
    }
};