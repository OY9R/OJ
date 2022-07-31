package com.leetcode.july;

import com.leetcode.Test;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ReplaceWords {
    // @Test(input = "[" +
    //         "[[\"cat\",\"bat\",\"rat\"],\"the cattle was rattled by the battery\"]," +
    //         "[[\"a\",\"b\",\"c\"],\"aadsfasf absbs bbab cadsfafs\"]" +
    //         "]", output = "[\"the cat was rat by the bat\",\"a a b c\"]")
    public String replaceWords(List<String> dictionary, String sentence) {
        Set<String> set = new HashSet<>();
        StringBuilder res = new StringBuilder();
        for (String word : dictionary) {
            set.add(word);
        }
        for (String word : sentence.split(" ")) {
            boolean flag = false;
            for (int i = 1; i <= word.length(); i++) {
                if (set.contains(word.substring(0, i))) {
                    res.append(" ").append(word.substring(0, i));
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                res.append(" ").append(word);
            }
        }
        return res.toString().substring(1);
    }
}
