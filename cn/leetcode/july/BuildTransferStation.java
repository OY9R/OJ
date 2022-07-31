package com.leetcode.july;

public class BuildTransferStation {
    public int buildTransferStation(int[][] area) {
        int[][] map = new int[area.length][area[0].length];
        for (int i = 0; i < area.length; i++) {
            for (int j = 0; j < area[0].length; j++) {
                if (area[i][j] == 1) {
                    for (int k = 0; k < area.length; k++) {
                        for (int l = 0; l < area[0].length; l++) {
                            map[k][l] += distance(i, j, k, l);
                        }
                    }
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (int k = 0; k < area.length; k++) {
            for (int l = 0; l < area[0].length; l++) {
                if (map[k][l] < min) {
                    min = map[k][l];
                }
            }
        }
        return min;
    }

    int distance(int p1x, int p1y, int p2x, int p2y) {
        int sum = 0;
        if (p1x > p2x) {
            sum += p1x - p2x;
        } else {
            sum += p2x - p1x;
        }
        if (p1y > p2y) {
            sum += p1y - p2y;
        } else {
            sum += p2y - p1y;
        }
        return sum;
    }
}
