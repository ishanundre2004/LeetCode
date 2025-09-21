class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int,int>>> availableShops;
    map<pair<int,int>, int> priceMap;
    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            availableShops[movie].insert({price, shop});
            priceMap[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        auto &s = availableShops[movie];
        int count = 0;
        for (auto &[price, shop] : s) {
            if (count == 5) break;
            res.push_back(shop);
            count++;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        availableShops[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        rented.erase({price, shop, movie});
        availableShops[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;
        for (auto &[price, shop, movie] : rented) {
            if (count == 5) break;
            ans.push_back({shop, movie});
            count++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */