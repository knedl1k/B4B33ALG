package cz.cvut.fel.alg;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 * This class tests the binary tree against two tests. To run tests in NetBeans press
 * shift+F6 or go to test classes (SimpleTreeTest.java and RandomTreeTest.java) and
 * use the same shortcut.
 *
 * @author Petr Ryšavý, Karel Horák
 */
public class TestMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JUnitCore junit = new JUnitCore();
        Result result = junit.run(cz.cvut.fel.alg.SimpleTreeTest.class);
        System.out.println("Test na jednoduchém stromu:");
        System.out.println("Nefunkčních " + result.getFailureCount() + " z " + result.getRunCount());
        if (result.getFailureCount() != 0) {
            System.out.println("Chyby:");
            for (Failure f : result.getFailures())
                System.out.printf("    %-30s %s\n", f.getDescription().getMethodName(), f.getMessage());
        }
        result = junit.run(cz.cvut.fel.alg.RandomTreeTest.class);
        System.out.println("--------------------------------------");
        System.out.println("Test na náhodném stromu:");
        System.out.println("Nefunkčních " + result.getFailureCount() + " z " + result.getRunCount());
        if (result.getFailureCount() != 0) {
            System.out.println("Chyby:");
            for (Failure f : result.getFailures())
                System.out.printf("    %-30s %s\n", f.getDescription().getMethodName(), f.getMessage());
        }
    }

}
