package com.leetcode.july;

import com.leetcode.Test;
import com.leetcode.TreeNode;

public class EvaluateTree {
    //@Test("([2,1,3,null,null,0,1])=true([0])=false")
    public boolean evaluateTree(TreeNode root) {
        switch (root.val) {
            case 0:
                return false;
            case 1:
                return true;
            case 2:
                return evaluateTree(root.left) || evaluateTree(root.right);
            case 3:
                return evaluateTree(root.left) && evaluateTree(root.right);
        }
        return false;
    }
}
