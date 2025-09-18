class TaskManager {
public:
    unordered_map<int, vector<int>> mp;
    set<vector<int>, greater<vector<int>>> s;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& it : tasks) {
            add(it[0], it[1], it[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, taskId, userId};
        s.insert({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto previous = mp[taskId];
        mp.erase(taskId);
        s.erase(previous);
        mp[taskId] = {newPriority, taskId, previous[2]};
        s.insert({newPriority, taskId, previous[2]});
    }

    void rmv(int taskId) {
        auto previous = mp[taskId];
        mp.erase(taskId);
        s.erase(previous);
    }

    int execTop() {
        if (s.size() == 0)
            return -1;
        auto it = *s.begin();
        s.erase(s.begin());
        return it[2];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */