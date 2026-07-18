class Solution {
public:
    int findGCD(vector<int>& nums) {
        int sam = INT_MAX;
        int lar = INT_MIN;
        int n  = nums.size();
        for(int i=0;i<n;i++){
            sam = min(sam,nums[i]);
            lar = max(lar,nums[i]);
        }
        return gcd(sam,lar);
    }
};