#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*

class Solution{
    public:
        int lengthOfLIS(vector<int>& nums){
            const int n = nums.size();
            vector<int> dp(n, 1);
            for(int i = 1; i < n; i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] > nums[j]){
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            return *max_element(begin(dp), end(dp));
        }
};

*/

class Solution{
    public:
        int lengthOfLIS(vector<int>& nums){
            vector<int> dp;
            for(int x : nums){
                auto it = lower_bound(begin(dp), end(dp), x);
                if(it == end(dp)){
                    dp.push_back(x);
                }else{
                    *it = x;
                }
            }
            return dp.size();
        }
};


int main(){
    int n;

    while(cin>>n){
        vector<int> nums;

        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            nums.push_back(x);
        }

        Solution s;
        int len = s.lengthOfLIS(nums);

        cout << "The length of the longest recreasing subsequence is : " << len << endl;
    }
    return 0;
}