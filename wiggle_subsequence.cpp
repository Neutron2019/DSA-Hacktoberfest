class Solution {
public:
int calculate(vector<int> nums,int i,bool isAlternate){
    int count=0;
    for(int i=1;i<nums.size();i++){
        if((nums[i]>nums[i-1])&&isAlternate){
            count++;
            isAlternate=false;
        }
        else if((nums[i]<nums[i-1])&&!isAlternate){
            count++;
            isAlternate=true;
        }
    }
    return count+1;
}
int wiggleMaxLength(vector<int>& nums) {
    if(nums.size()<2) return nums.size();
    else return max(calculate(nums,0,true), calculate(nums,0,false));
}
};

//Question: https://leetcode.com/problems/wiggle-subsequence/
//Greedy
