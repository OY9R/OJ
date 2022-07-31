package com.leetcode.july;

import com.leetcode.Test;

public class MinSwaps {
    //@Test(input = "[[[1,0,1,0,1,0]],[[0,0,0,1,0]],[[1,1,0,1,0,1,0,0,1,0,1]],[[1,0,1,0,1,0,0,0,1,1,0,1]]]", output = "[1,0,2,3]")
    public int minSwaps(int[] chess) {
        int left = 0, right, black = 0;
        for (int j : chess) {
            if (j == 1) black++;
        }
        if (black == 1) return 0;
        right = black - 1;
        int res = Integer.MAX_VALUE;
        for (; left < chess.length - black; left++) {
            int num = 0;
            for (int i = left; i <= right; i++) {
                if (chess[i] == 0) num++;
            }
            if (num < res) res = num;
        }
        return res;
    }
}
