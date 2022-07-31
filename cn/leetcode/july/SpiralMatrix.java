package com.leetcode.july;

import com.leetcode.Test;

public class SpiralMatrix {
    // @Test(
    //         input = "[" +
    //                 "[3,5,[3,0,2,6,8,1,7,9,4,2,5,5,0]]," +
    //                 "[1,4,[0,1,2]]" +
    //                 "]",
    //         output = "[" +
    //                 "[[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]," +
    //                 "[[0,1,2,-1]]" +
    //                 "]"
    // )
    public int[][] spiralMatrix(int m, int n, int[] head) {
        int[][] map = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = -1;
            }
        }
        int i = 0, j = 0, direction = 0;

        for (int a : head) {
            if (direction == 1) {
                if (i + 1 < m && map[i + 1][j] == -1) {
                    i++;
                    map[i][j] = a;
                } else {
                    direction = 2;
                }
            } else if (direction == 0) {
                if (j + 1 < n && map[i][j + 1] == -1) {
                    j++;
                    map[i][j] = a;
                } else {
                    direction = 1;
                }
            } else if (direction == 3) {
                if (i > 0 && map[i - 1][j] == -1) {
                    i--;
                    map[i][j] = a;
                } else {
                    direction = 0;
                }
            } else {
                if (j > 0 && map[i][j - 1] == -1) {
                    j--;
                    map[i][j] = a;
                } else {
                    direction = 3;
                }
            }
        }
        return map;
    }
}
