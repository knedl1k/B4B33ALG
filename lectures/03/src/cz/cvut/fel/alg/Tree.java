package cz.cvut.fel.alg;

import java.util.List;

/**
 * Class representing a binary tree.
 *
 * @author knedl1k 2023
 */
public class Tree {
    private int value;
    private Tree leftSubTree;
    private Tree rightSubTree;

    public Tree(int value) {
        this.value = value;
    }

    public Tree(int value, Tree leftSubTree, Tree rightSubTree) {
        this.value = value;
        this.leftSubTree = leftSubTree;
        this.rightSubTree = rightSubTree;
    }

    public int getValue() {
        return value;
    }
    public Tree getLeftSubTree() {
        return leftSubTree;
    }
    public Tree getRightSubTree() {
        return rightSubTree;
    }
    public void setLeftSubTree(Tree leftSubTree) {
        this.leftSubTree = leftSubTree;
    }
    public void setRightSubTree(Tree rightSubTree) {
        this.rightSubTree = rightSubTree;
    }

    /**
     * This method finds minimal value that is stored in the tree.
     */
    public int minValue() {
        Tree leftSubTree=getLeftSubTree();
        Tree rightSubTree=getRightSubTree();
        int leftValue=2147483647;
        int rightValue=2147483647;
        if(leftSubTree!=null){
            leftValue=leftSubTree.minValue();
        }
        if(rightSubTree!=null){
            rightValue=rightSubTree.minValue();
        }
        return (Math.min(leftValue,rightValue),value);
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * This method sums values of all nodes of the tree.
     */
    public int sumValues() {
        Tree leftSubTree=getLeftSubTree();
        Tree rightSubTree=getRightSubTree();
        int leftValue=0;
        int rightValue=0;
        if(leftSubTree!=null)
            leftValue=leftSubTree.sumValues();
        if(rightSubTree!=null)
            rightValue=rightSubTree.sumValues();
        return rightValue+leftValue+1;
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * Computes the number of all nodes in the tree.
     */
    public int size() {
        Tree leftSubTree=getLeftSubTree();
        Tree rightSubTree=getRightSubTree();
        int leftValue=0;
        int rightValue=0;
        if(leftSubTree!=null)
            leftValue=leftSubTree.size();
        if(rightSubTree!=null)
            rightValue=rightSubTree.size();
        return rightValue+leftValue+getValue();
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * This method performs an inorder traversal of the tree and adds values of
     * visited nodes in a list based on this ordering.
     */
    public void walkInorder(List<Integer> list) {
        if(getLeftSubTree()!=null)
            getLeftSubTree().walkInorder(list);
        list.add(value);
        if(getRightSubTree()!=null)
            getRightSubTree().walkInorder(list);
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * This method performs an preorder traversal of the tree and adds values of
     * visited nodes in a list based on this ordering.
     */
    public void walkPreorder(List<Integer> list) {
        list.add(value);
        if(getLeftSubTree()!=null)
            getLeftSubTree().walkPreorder(list);
        if(getRightSubTree()!=null)
            getRightSubTree().walkPreorder(list);
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * This method performs an postorder traversal of the tree and adds values of
     * visited nodes in a list based on this ordering.
     */
    public void walkPostorder(List<Integer> list) {
        if(getLeftSubTree()!=null)
            getLeftSubTree().walkPostorder(list);
        if(getRightSubTree()!=null)
            getRightSubTree().walkPostorder(list);
        list.add(value);
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * This method computes number of leaves in the tree.
     */
    public int numberOfLeaves() {
        if(getLeftSubTree()==null && getRightSubTree()==null)
            return 1;
        int numOfLeavesLeft=0, numberOfLeavesRight=0;
        if(getLeftSubTree()!=null)
            numOfLeavesLeft=getLeftSubTree().numberOfLeaves();
        if(getRightSubTree()!=null)
            numOfLeavesRight=getRightSubTree().numberOfLeaves();
        return numOfLeavesLeft+numOfLeavesRight;
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * This method calculates the depth of the tree. A tree with a single node
     * with no children has depth equal to 0.
     */
    public int depth() {
        int rightDepth=0,leftDepth=0;
        if(getLeftSubTree()!=null)
            leftDepth=getLeftSubTree().depth() +1; //+1 adds for one new layer
        if(getRightSubTree()!=null)
            rightDepth=getRightSubTree().depth() +1;
        return Math.max(rightDepth,leftDepth);
        //throw new UnsupportedOperationException("Not implemented yet.");
    }

    /**
     * After calling this method the tree will fulfil the heap property:
     *
     * Value of any node x is smaller than the value of x's left child and also
     * smaller than the value of x's right child.
     */
    public void heapify() {
        
        throw new UnsupportedOperationException("Not implemented yet.");
    }
}
