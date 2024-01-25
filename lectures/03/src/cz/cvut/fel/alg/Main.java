package cz.cvut.fel.alg;

public class Main
{
    /**
     * Demo main function.
     */
    public static void main(String[] args)
    {
        // Use your editor matching brackets highlight capability
        // to see the particular subtrees in the tree code.

        String treePR1 = "(42(13()(25(17()())(27(26()())(31()()))))(48(43()())(95()(98()()))))";
        String treePR5 = "(50(47(71(45()())(98()()))())(62()(3(87()())(79()()))))";
        String treex = "(12(22(32(42()(101(177(222()())())()))())())(900))";

        String treeCode = treePR1;

        /**
         * TreeBuilder accepts a string containing a prefix parentheses notation and
         * produces the corresponding binary tree representation. Tree Notation
         * grammar : empty_tree := () tree := empty_tree | (integer tree tree)
         */
        Tree t1 = TreeBuilder.buildTree(treeCode);
        Paper.printTree(t1, 20, 80);  // paper picture height and width
    }
}
