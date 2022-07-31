package com.leetcode.july;

import com.leetcode.Test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MaximumSum {
    //@Test("*#2([18,43,36,13,7])=54([10,12,19,14])=-1")
    public int maximumSum(int[] nums) {
        List<List<Integer>> m = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            m.add(new ArrayList<>());
        }
        for (int num : nums) {
            m.get(MumSum(num)).add(num);
        }
        int max = -1;
        for (List<Integer> list : m) {
            if (list.size() > 1) {
                Collections.sort(list, Collections.reverseOrder());
                if (list.get(0) + list.get(1) > max) {
                    max = list.get(0) + list.get(1);
                }
            }
        }
        return max;
    }
    private int MumSum(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
}
