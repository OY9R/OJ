package com.leetcode.july;

public class ZeroFilledSubarray {
    public long zeroFilledSubarray(int[] nums) {
        long ans = 0;
        long tmp = 1;
        for (int num : nums) {
            if (num == 0) {
                ans += tmp++;
            } else {
                tmp = 1;
            }
        }
        return ans;
    }
}
