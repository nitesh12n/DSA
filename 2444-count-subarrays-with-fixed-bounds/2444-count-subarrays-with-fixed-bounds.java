class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int left = -1, minIndex = -1, maxIndex = -1;
        long ans = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < minK || nums[i] > maxK)
                left = i;

            if (nums[i] == minK)
                minIndex = i;
            if (nums[i] == maxK)
                maxIndex = i;

            ans = ans + Math.max(0, Math.min(minIndex, maxIndex) - left);
        }
        return ans;
    }
}
