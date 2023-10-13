package cz.cvut.fel.alg;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import org.junit.Before;
import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runners.MethodSorters;

import static org.hamcrest.CoreMatchers.equalTo;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.Matchers.contains;
import static org.hamcrest.Matchers.greaterThanOrEqualTo;
import static org.junit.Assert.assertThat;

/**
 * Tests the tree on a tree that is on slides.
 *
 * @author Petr Ryšavý, Karel Horák
 */
@FixMethodOrder(MethodSorters.NAME_ASCENDING)
public class SimpleTreeTest {

    private Tree tree;

    @Before
    public void buildSimpleTree() {
        tree = new Tree(42,
                new Tree(13,
                        null,
                        new Tree(25,
                                new Tree(17),
                                new Tree(27,
                                        new Tree(26),
                                        new Tree(31)))),
                new Tree(48,
                        new Tree(43),
                        new Tree(95,
                                null,
                                new Tree(98))));
    }

    @Test
    public void test1_MinValue() {
        assertThat(tree.minValue(), is(equalTo(13)));
    }

    @Test
    public void test2_SumValues() {
        assertThat(tree.sumValues(), is(equalTo(465)));
    }

    @Test
    public void test3_Size() {
        assertThat(tree.size(), is(equalTo(11)));
    }

    @Test
    public void test4_WalkInorder() {
        List<Integer> list = new ArrayList<>(11);
        tree.walkInorder(list);
        assertThat(list, contains(13, 17, 25, 26, 27, 31, 42, 43, 48, 95, 98));
    }

    @Test
    public void test5_WalkPreorder() {
        List<Integer> list = new ArrayList<>(11);
        tree.walkPreorder(list);
        assertThat(list, contains(42, 13, 25, 17, 27, 26, 31, 48, 43, 95, 98));
    }

    @Test
    public void test6_WalkPostorder() {
        List<Integer> list = new ArrayList<>(11);
        tree.walkPostorder(list);
        assertThat(list, contains(17, 26, 31, 27, 25, 13, 43, 98, 95, 48, 42));
    }

    @Test
    public void test7_NumberOfLeaves() {
        assertThat(tree.numberOfLeaves(), is(equalTo(5)));
    }

    @Test
    public void test8_Depth() {
        assertThat(tree.depth(), is(equalTo(4)));
    }

    @Test
    public void test9_Heapify() {
        tree.heapify();
        System.err.println(tree);
        assertThat(tree.getValue(), is(equalTo(13)));
        Deque<Tree> deque = new LinkedList<>();
        deque.add(tree);
        while (!deque.isEmpty()) {
            Tree peak = deque.removeFirst();
            if (peak.getLeftSubTree() != null) {
                assertThat(peak.getLeftSubTree().getValue(), is(greaterThanOrEqualTo(peak.getValue())));
                deque.addLast(peak.getLeftSubTree());
            }
            if (peak.getRightSubTree()!= null) {
                assertThat(peak.getRightSubTree().getValue(), is(greaterThanOrEqualTo(peak.getValue())));
                deque.addLast(peak.getRightSubTree());
            }
        }
    }
}
