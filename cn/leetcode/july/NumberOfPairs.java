package com.leetcode.july;

import com.leetcode.Test;

public class NumberOfPairs {
    //@Test("*#1([1,3,2,1,3,2,2])=[3,1]([1,1])=[1,0]([0])=[0,1]")
    public int[] numberOfPairs(int[] nums) {
        boolean[] m = new boolean[101];
        int ans = 0;
        for (int num : nums) {
            if (m[num]) {
                m[num] = false;
                ans++;
            } else {
                m[num] = true;
            }
        }
        int sum = 0;
        for (boolean b : m) {
            if (b) {
                sum++;
            }
        }
        return new int[]{ans,sum};
    }
}
