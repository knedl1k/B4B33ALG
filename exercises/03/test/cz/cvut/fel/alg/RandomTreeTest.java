package cz.cvut.fel.alg;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import org.junit.Before;
import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runners.MethodSorters;

import static org.hamcrest.CoreMatchers.equalTo;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.Matchers.greaterThanOrEqualTo;
import static org.junit.Assert.assertThat;

/**
 * Tests the tree on a randomly build tree.
 *
 * @author Petr Ryšavý, Karel Horák
 */
@FixMethodOrder(MethodSorters.NAME_ASCENDING)
public class RandomTreeTest {

    private Tree tree;

    @Before
    public void buildRandomTree() {
        Random r = new Random();
        Deque<Tree> deque = new LinkedList<>();
        tree = new Tree(r.nextInt(1000));
        deque.add(tree);
        int nodes = 0;
        while (!deque.isEmpty()) {
            Tree peak = deque.removeFirst();
            nodes++;
            if (r.nextBoolean()&& nodes < 1000) {
                Tree t = new Tree(r.nextInt(1000));
                peak.setLeftSubTree(t);
                deque.addLast(t);
            }
            if (r.nextBoolean() && nodes < 1000) {
                Tree t = new Tree(r.nextInt(1000));
                peak.setRightSubTree(t);
                deque.addLast(t);
            }
        }
    }

    @Test
    public void test1_MinValue() {
        assertThat(tree.minValue(), is(equalTo(min(dumpToArray(tree)))));
    }

    @Test
    public void test2_SumValues() {
        assertThat(tree.sumValues(), is(equalTo(sum(dumpToArray(tree)))));
    }

    @Test
    public void test3_Size() {
        assertThat(tree.size(), is(equalTo(dumpToArray(tree).size())));
    }

    @Test
    public void test4_WalkInorder() {
        List<Integer> list = new ArrayList<>();
        tree.walkInorder(list);
        List<Integer> lst = new ArrayList<>();
        dumpIn(tree, lst);
        assertThat(list, is(equalTo(lst)));
    }

    @Test
    public void test5_WalkPreorder() {
        List<Integer> list = new ArrayList<>();
        tree.walkPreorder(list);
        assertThat(list, is(equalTo(dumpToArray(tree))));
    }

    @Test
    public void test6_WalkPostorder() {
        List<Integer> list = new ArrayList<>(11);
        tree.walkPostorder(list);
        List<Integer> lst = new ArrayList<>();
        dumpPost(tree, lst);
        assertThat(list, is(equalTo(lst)));
    }

    @Test
    public void test7_NumberOfLeaves() {
        Count c = new Count();
        walkTree(new Action() {
            @Override
            public void in(Tree t) {
                if (t.getLeftSubTree() == null && t.getRightSubTree() == null)
                    c.count++;
            }
        });
        assertThat(tree.numberOfLeaves(), is(equalTo(c.count)));
    }

    @Test
    public void test8_Depth() {
        assertThat(tree.depth(), is(equalTo(depth(tree))));
    }

    @Test
    public void test9_Heapify() {
        tree.heapify();
        assertThat(tree.getValue(), is(equalTo(min(dumpToArray(tree)))));
        Deque<Tree> deque = new LinkedList<>();
        deque.add(tree);
        while (!deque.isEmpty()) {
            Tree peak = deque.removeFirst();
            if (peak.getLeftSubTree() != null) {
                assertThat(peak.getLeftSubTree().getValue(), is(greaterThanOrEqualTo(peak.getValue())));
                deque.addLast(peak.getLeftSubTree());
            }
            if (peak.getRightSubTree() != null) {
                assertThat(peak.getRightSubTree().getValue(), is(greaterThanOrEqualTo(peak.getValue())));
                deque.addLast(peak.getRightSubTree());
            }
        }
    }

    private void walkTree(Action a) {
        Deque<Tree> deque = new LinkedList<>();
        deque.add(tree);
        while (!deque.isEmpty()) {
            Tree peak = deque.removeFirst();
            a.in(peak);
            if (peak.getRightSubTree() != null)
                deque.addFirst(peak.getRightSubTree());
            if (peak.getLeftSubTree() != null)
                deque.addFirst(peak.getLeftSubTree());
        }
    }

    private int min(Iterable<Integer> it) {
        int min = Integer.MAX_VALUE;
        for (Integer i : it)
            min = Math.min(min, i);
        return min;
    }

    private int sum(Iterable<Integer> it) {
        int sum = 0;
        for (Integer i : it)
            sum += i;
        return sum;
    }

    private List<Integer> dumpToArray(Tree t) {
        final ArrayList<Integer> lst = new ArrayList<>();
        walkTree(new Action() {
            @Override
            public void in(Tree t) {
                lst.add(t.getValue());
            }
        });
        return lst;
    }

    private void dumpIn(Tree t, List<Integer> lst) {
        if(t == null)
            return;

        dumpIn(t.getLeftSubTree(),lst);
        lst.add(t.getValue());
        dumpIn(t.getRightSubTree(), lst);
    }

    private void dumpPost(Tree t, List<Integer> lst) {
        if(t == null)
            return;

        dumpPost(t.getLeftSubTree(),lst);
        dumpPost(t.getRightSubTree(), lst);
        lst.add(t.getValue());
    }

    private int depth(Tree t) {
        return 1 + Math.max(t.getLeftSubTree() == null ? -1 : depth(t.getLeftSubTree()), t.getRightSubTree() == null ? -1 : depth(t.getRightSubTree()));
    }
}

abstract class Action {
    public void in(Tree t) {
    }
}

class Count {
    int count = 0;
}
