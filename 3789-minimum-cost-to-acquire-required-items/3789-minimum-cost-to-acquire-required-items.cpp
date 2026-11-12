#define ll long long
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        return (((ll)min(costBoth, cost1 + cost2) * (ll)min(need1, need2)) +
                ((need1 > need2)
                     ? ((ll)min(costBoth, cost1) * (ll)(need1 - need2))
                     : ((ll)min(costBoth, cost2) * (ll)(need2 - need1))));
    }
};