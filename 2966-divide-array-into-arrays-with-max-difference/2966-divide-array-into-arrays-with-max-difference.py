class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        
        if len(nums)%3 != 0:
            return []
        
        nums.sort()
        res = []
        for i in range(1, len(nums) - 1, 3):
            
            if abs(nums[i-1] - nums[i+1]) <=k:
                res.append([nums[i-1], nums[i], nums[i+1]])
            else:
                return []
            
        return res
                
                    
            
        
        
        
        
        