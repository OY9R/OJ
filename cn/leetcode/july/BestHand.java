package com.leetcode.july;

import com.leetcode.Test;

public class BestHand {
    @Test("*([13,2,3,1,9],['a','a','a','a','a'])=\"Flush\"([4,4,3,4,4],['d','a','a','b','c'])=\"Three of a Kind\"")
    public String bestHand(int[] ranks, char[] suits) {
        if (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4]) {
            return "Flush";
        }
        int[] hand = new int[14];
        for (int rank : ranks) {
            hand[rank] += 1;
        }
        for (int i : hand) {
            if (i >= 3) {
                return "Three of a Kind";
            }
        }
        for (int i : hand) {
            if (i >= 2) {
                return "Pair";
            }
        }
        return "High Card";
    }
}
