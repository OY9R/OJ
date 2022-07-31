package com.leetcode.july;

import com.leetcode.Test;

public class FillCups {
    //@Test("*now([1,4,2])=4([5,4,4])=7")
    public int fillCups(int[] amount) {
        int max = max(amount[0], amount[1], amount[2]);
        int sum = amount[0] + amount[1] + amount[2];
        return max + max(0, (sum - max - max + 1) / 2);
    }
    int max(int... a) {
        int max = Integer.MIN_VALUE;
        for (int j : a) {
            if (j > max) max = j;
        }
        return max;
    }
}
