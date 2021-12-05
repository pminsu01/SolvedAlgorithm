class Solution {
    
public:
    int rob(vector<int>& nums) {

        int maxArraySize = nums.size();
    
        int* maxNum = new int[maxArraySize];
        
        maxNum[0] = nums[0];
        if(nums.size() < 2) return maxNum[0]; // size가 1개일 때 max는 0번째 Index
        
        maxNum[1] = max(nums[0], nums[1]);
        if(nums.size() < 3) return max(maxNum[0], maxNum[1]); // size가 2개일 때 0번째 또는 1번째 Index 중 큰 값이 max값이다.
        
        for(int i=2; i<nums.size(); i++) {

            maxNum[i] = max(maxNum[i-2]+nums[i], maxNum[i-1]);
        }
        
        return maxNum[maxArraySize-1];
    }
    
    int max(int a, int b){
        
        return a > b ? a:b;
    }
};