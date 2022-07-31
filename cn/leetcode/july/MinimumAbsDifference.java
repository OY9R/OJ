package com.leetcode.july;

import com.leetcode.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MinimumAbsDifference {
    //@Test(input = "[[[4,2,1,3]],[[1,3,6,10,15]],[[3,8,-10,23,19,-4,-14,27]]]", output = "[[[1,2],[2,3],[3,4]],[[1,3]],[[-14,-10],[19,23],[23,27]]]")
    public List<List<Integer>> minimumAbsDifference(List<Integer> a) {
        Integer[] arr = a.toArray(new Integer[0]);
        int n = arr.length;
        Arrays.sort(arr);
        int best = Integer.MAX_VALUE;
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for (int i = 0; i < n - 1; ++i) {
            int delta = arr[i + 1] - arr[i];
            if (delta < best) {
                best = delta;
                ans.clear();
                List<Integer> pair = new ArrayList<Integer>();
                pair.add(arr[i]);
                pair.add(arr[i + 1]);
                ans.add(pair);
            } else if (delta == best) {
                List<Integer> pair = new ArrayList<Integer>();
                pair.add(arr[i]);
                pair.add(arr[i + 1]);
                ans.add(pair);
            }
        }
        return ans;
    }
}
