package cz.cvut.fel.alg;

/**
 * Playground for O(n^2) sorting algorithms
 */
public class Sorting {

  public static void main(String[] args) {
    abcSort(getDatabase());
  }

  public static Person[] getDatabase() {
    return new Person[] {
        new Person("Franta", 32),
        new Person("Pepa", 17),
        new Person("Petr", 25),
        new Person("Jana", 23), // meow
        new Person("David", 23),
        new Person("Martina", 25),
        new Person("Lojza", 7),
        new Person("Hanka", 23)
    };
  }

  public static void insertSort(Person[] a) {
    int j;
    Person insVal;

    System.out.println("INSERT SORT");
    System.out.println("===========");

    print(a);

    for (int i = 1; i < a.length; i++) {
      insVal = a[i];
      j = i - 1;
      while ((j >= 0) && (a[j].getAge() > insVal.getAge())) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = insVal;

      print(a);
    }
  }

  public static void selectionSort(Person[] a) {
    int N = a.length;

    System.out.println("SELECTION SORT");
    System.out.println("==============");

    print(a);

    for (int i = 0; i < N - 1; i++) {
      // select min
      int jmin = i;
      for (int j = i + 1; j < N; j++) {
        if (a[j].getAge() < a[jmin].getAge()) {
          jmin = j;
        }
      }
      Person min = a[jmin];
      for (int j = jmin; j > i; j++) {
        a[j] = a[j - 1];
      }
      a[i] = min;

      print(a);
    }
  }

  public static void print(Person[] a) {
    for (Person p : a) {
      System.out.printf("%9s %2d ", p.getName(), p.getAge());
    }
    System.out.println();
  }

  public static void abcSort(Person[] a) {
    System.out.println("ABCSORT");
    System.out.println("=======");

    print(a);

    for (int i = 0; i < a.length / 2; i++) {
      boolean swapped = false;
      for (int j = i; j < a.length - i - 1; j++) {
        if (a[j].getAge() < a[j + 1].getAge()) {
          Person tmp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = tmp;
          swapped = true;
        }
      }
      for (int j = a.length - 2 - i; j > i; j--) {
        if (a[j].getAge() > a[j - 1].getAge()) {
          Person tmp = a[j];
          a[j] = a[j - 1];
          a[j - 1] = tmp;
          swapped = true;
        }
      }

      print(a);

      if (!swapped)
        break;
    }
  }

}
