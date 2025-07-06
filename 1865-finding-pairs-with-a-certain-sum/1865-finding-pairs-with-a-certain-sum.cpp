class FindSumPairs {
public:
    vector<int>nums1,nums2;
    unordered_map<int,int>freq;
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        this->nums1=n1;
        this->nums2=n2;
        for(int n: nums2)
        {
            freq[n]++;
        }
    }

    
    void add(int i, int val) {
        --freq[nums2[i]];
        nums2[i]+=val;
        ++freq[nums2[i]];
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<nums1.size();i++)
        {
            int second=tot-nums1[i];
            if(freq.count(second))
            {
                cnt+=freq[second];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */