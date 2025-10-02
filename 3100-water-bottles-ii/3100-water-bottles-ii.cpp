class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = numBottles;
        int bottlesDrunk = numBottles;
        while(emptyBottles >= numExchange){
            emptyBottles -= numExchange;
            bottlesDrunk++;
            numExchange++;
            emptyBottles++;
        } 
        return bottlesDrunk;
    }
};