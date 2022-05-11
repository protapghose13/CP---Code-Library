int lisStrictlyIncreasing(vector<int>& nums) {
    int n = nums.size();
    assert(n > 0);
    int mxNum = nums[0], mnNum = nums[0];
    for(int i=1;i<n;i++){
        mxNum = max(mxNum, nums[i]);
        mnNum = min(mnNum, nums[i]);
    }

    vector<int>inc(n+1, mxNum + 1);
    inc[0] = mnNum - 1;
    
    int ans = 0;
    for(int i=0;i<n;i++){
        int low = 0, high = n;
        
        while(high - low > 1){
            int mid = (low + high) >> 1;
            
            if(inc[mid] <= nums[i]){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        
        int idx = (inc[low] > nums[i] ? low : high);
        inc[idx] = nums[i];
        ans = max(ans, idx);
    }
    
    return ans;
}