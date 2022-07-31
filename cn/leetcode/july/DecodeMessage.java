package com.leetcode.july;

import com.leetcode.Test;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

public class DecodeMessage {
    // @Test(  input =
    //         "[['the quick brown fox jumps over the lazy dog','vkbs bs t suepuv']," +
    //         "['eljuxhpwnyrdgtqkviszcfmabo','zwx hnfx lqantp mnoeius ycgk vcnjrdb']]",
    //         output =
    //         "['this is a secret','the five boxing wizards jump quickly']"
    // )
    //@Test("('the quick brown fox jumps over the lazy dog','vkbs bs t suepuv')='this is a secret'" +
    //      "('eljuxhpwnyrdgtqkviszcfmabo','zwx hnfx lqantp mnoeius ycgk vcnjrdb')='the five boxing wizards jump quickly'")
    public String decodeMessage(String key, String message) {
        Map<Character,Character> keyMap = new HashMap<>();
        for (char c = 'a'; c <= 'z';) {
            for (char k : key.toCharArray()) {
                if (k != ' ' && keyMap.putIfAbsent(k, c) == null) {
                    c++;
                }
            }
        }
        StringBuffer sb = new StringBuffer();
        for (char m : message.toCharArray()) {
            if (m != ' ') {
                sb.append(keyMap.get(m));
            } else {
                sb.append(' ');
            }
        }
        return sb.toString();
    }
}
