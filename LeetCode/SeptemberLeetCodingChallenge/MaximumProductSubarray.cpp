class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> dp1=nums;
		vector<int> dp2=nums;
		int ans=nums[0];
		for(int i=1;i<nums.size();i++)
		{
			ans=max({ans,nums[i],nums[i]*dp1[i-1],nums[i]*dp2[i-1]});
			dp1[i]=max({dp2[i-1]*nums[i],nums[i],dp1[i-1]*nums[i]});
			dp2[i]=min({dp2[i-1]*nums[i],nums[i],dp1[i-1]*nums[i]});
		}
		return ans;
	}
};
