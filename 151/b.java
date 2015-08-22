import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class b {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    List<Friend> friends = new ArrayList<>();
    int n = sc.nextInt();

    for (int i = 0; i < n; ++i) {
      int size = sc.nextInt();
      Friend friend = new Friend(sc.next());

      for (int j = 0; j < size; ++j) {
        String number = sc.next();

        if (isTaxiNumber(number)) {
          ++friend.taxi;
        } else if (isPizzaNumber(number)) {
          ++friend.pizza;
        } else {
          ++friend.girls;
        }
      }

      friends.add(friend);
    }

    sc.close();
    System.out.print("If you want to call a taxi, you should call: ");
    System.out.println(bestTaxi(friends) + ".");
    System.out.print("If you want to order a pizza, you should call: ");
    System.out.println(bestPizza(friends) + ".");
    System.out.print("If you want to go to a cafe with a wonderful girl, you should call: ");
    System.out.println(bestGirls(friends) + ".");
  }

  private static String bestTaxi(List<Friend> friends) {
    return joinNames(allMaxNames(friends, Field.TAXI));
  }

  private static String bestPizza(List<Friend> friends) {
    return joinNames(allMaxNames(friends, Field.PIZZA));
  }

  private static String bestGirls(List<Friend> friends) {
    return joinNames(allMaxNames(friends, Field.GIRLS));
  }

  private static boolean isPizzaNumber(String number) {
    List<Integer> digits = toIntArray(number);
    int prev = digits.get(0);

    for (int i = 1; i < digits.size(); ++i) {
      if (digits.get(i) >= prev) {
        return false;
      }

      prev = digits.get(i);
    }

    return true;
  }

  private static boolean isTaxiNumber(String number) {
    List<Integer> digits = toIntArray(number);
    int first = digits.get(0);

    for (int i = 1; i < digits.size(); ++i) {
      if (first != digits.get(i)) {
        return false;
      }
    }

    return true;
  }

  private static List<Integer> toIntArray(String number) {
    List<Integer> result = new ArrayList<>();

    for (char digit: number.toCharArray()) {
      if (digit != '-') {
        result.add(digit - '0');
      }
    }

    return result;
  }

  private static String joinNames(List<String> names) {
    StringBuilder result = new StringBuilder();

    for (int i = 0; i < names.size(); ++i) {
      result.append(names.get(i));

      if (i + 1 < names.size()) {
        result.append(", ");
      }
    }

    return result.toString();
  }

  private static Integer getFieldValue(Friend friend, Field field) {
    if (field == Field.TAXI) {
      return friend.taxi;
    } else if (field == Field.PIZZA) {
      return friend.pizza;
    }

    return friend.girls;
  }

  private static List<String> allMaxNames(List<Friend> friends, Field field) {
    List<String> names = new ArrayList<>();
    int maxValue = 0;

    for (int i = 0; i < friends.size(); ++i) {
      maxValue = Math.max(maxValue, getFieldValue(friends.get(i), field));
    }

    for (int i = 0; i < friends.size(); ++i) {
      if (getFieldValue(friends.get(i), field) == maxValue) {
        names.add(friends.get(i).name);
      }
    }

    return names;
  }

  private enum Field {TAXI, PIZZA, GIRLS}

  private static class Friend {
    public String name;
    public Integer taxi = 0, pizza = 0, girls = 0;

    public Friend(String name) {
      this.name = name;
    }
  }
}
