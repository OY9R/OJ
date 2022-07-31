package com.leetcode.july;

import java.util.*;

public class NumberContainers {

    TreeMap<Integer,Integer>i2n;
    public NumberContainers() {
        i2n = new TreeMap<>();
    }

    public void change(int index, int number) {
        i2n.put(index, number);
    }

    public int find(int number) {
        Integer[] integers = (Integer[]) i2n.keySet().toArray();
        Arrays.sort(integers);
        // todo
        return 0;
    }

    public static void main(String[] args) {
        NumberContainers n = new NumberContainers();
        System.out.println(n.find(10));
        n.change(1,10);
        System.out.println(n.find(10));
        n.change(1,20);
        System.out.println(n.find(10));
        n.change(2,10);
        System.out.println(n.find(10));
        System.out.println(n.find(20));

    }
}
