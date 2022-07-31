package com.leetcode.july;

import com.leetcode.Test;

public class CanChange {
    //@Test("(\"_L__R__R_\",\"L______RR\")=true(\"R_L_\",\"__LR\")=false(\"_R\",\"R_\")=false")
    public boolean canChange(String start, String target) {
        char[] starts = start.toCharArray();
        char[] targets = target.toCharArray();
        int l = 0, r = 0;
        for (int i = 0; i < targets.length; i++) {
            if (targets[i] == 'L') {
                l++;
            }
            if (starts[i] == 'L') {
                l--;
            }
            if (targets[i] == 'R') {
                r++;
            }
            if (starts[i] == 'R') {
                r--;
            }
        }
        if (l != 0 || r != 0) {
            return false;
        }
        for (int i = 0; i < targets.length; i++) {
            if (targets[i] == 'L') {
                int j = i;
                while (j < targets.length - 1 && (starts[j] == '_' || starts[j] == 'l')) j++;
                if (starts[j] == 'L') {
                    starts[j] = 'l';
                } else {
                    return false;
                }
            }
        }
        for (int i = targets.length - 1; i >= 0; i--) {
            if (targets[i] == 'R') {
                int j = i;
                while (j > 0 && (starts[j] == '_' || starts[j] == 'r')) j--;
                if (starts[j] == 'R') {
                    starts[j] = 'r';
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
