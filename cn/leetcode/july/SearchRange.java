package com.leetcode.july;

import com.leetcode.Test;

public class SearchRange {
    //@Test(value = "([5,7,7,8,8,10],8)=[3,4]([5,7,7,8,8,10],6)=[-1,-1]",input = "[[[5,7,7,8,8,10],8],[[5,7,7,8,8,10],6],[[],0]]",output = "[[3,4],[-1,-1],[-1,-1]]")
    public int[] searchRange(int[] nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.length && nums[leftIdx] == target && nums[rightIdx] == target) {
            return new int[]{leftIdx, rightIdx};
        }
        return new int[]{-1, -1};
    }

    public int binarySearch(int[] nums, int target, boolean lower) {
        int left = 0, right = nums.length - 1, ans = nums.length;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}
