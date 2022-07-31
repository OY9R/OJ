package com.leetcode.july;

import com.leetcode.Test;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class CanReceiveAllSignals {
    //@Test("([[0,40],[10,15],[20,30]])=false([[2,8],[8,14]]],[[[9,12],[2,3]])=true([[2,8],[8,14]])=true")
    public boolean canReceiveAllSignals(int[][] intervals) {
        if (intervals.length == 0) {
            return true;
        }
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));
        for (int i = 0; i < intervals.length - 1; ++i) {
            if (intervals[i + 1][0] < intervals[i][1]) {
                return false;
            }
        }
        return true;
    }
}
