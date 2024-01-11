class Solution:
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        def permute(temp, index):
                    
            if index == len(temp):
                res.append(temp.copy())
                
            for i in range(index, len(temp)): 
                temp[index], temp[i] = temp[i], temp[index]
                permute(temp, index + 1)
                temp[index], temp[i] = temp[i], temp[index]
                
        permute(nums, 0)
        return res
                
