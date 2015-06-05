import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
//import java.util.Comparator;
//import java.util.Collections;
//import java.util.Stack;

public class b {

    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        List<Friend> friends = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int size = sc.nextInt();
            Friend friend = new Friend(sc.next());

            for (int j = 0; j < size; j++) {
                String number = sc.next();

                if (isTaxiNumber(number)) {
                    friend.taxi++;
                } else if (isPizzaNumber(number)) {
                    friend.pizza++;
                } else {
                    friend.girls++;
                }
            }

            friends.add(friend);
        }

        sc.close();

        /*for (int i = 0; i < n; i++) {
            System.out.print(friends.get(i).name + "'s ");
            System.out.print("taxi: " + friends.get(i).taxi);
            System.out.print(", pizza: " + friends.get(i).pizza);
            System.out.println(", girls: " + friends.get(i).girls);
        }*/

        System.out.print("If you want to call a taxi, you should call: ");
        System.out.println(bestTaxi(friends) + ".");

        System.out.print("If you want to order a pizza, you should call: ");
        System.out.println(bestPizza(friends) + ".");

        System.out.print(
            "If you want to go to a cafe with a wonderful girl, you should call: "
        );
        System.out.println(bestGirls(friends) + ".");
    }

    private static String bestTaxi(final List<Friend> friends) {
        //List<Friend> newFriends = new ArrayList<>(friends);
        //Collections.sort(newFriends, new FriendComparator(Field.TAXI));

        return joinNames(allMaxNames(friends, Field.TAXI));
    }

    private static String bestPizza(final List<Friend> friends) {
        //List<Friend> newFriends = new ArrayList<>(friends);
        //Collections.sort(newFriends, new FriendComparator(Field.PIZZA));

        return joinNames(allMaxNames(friends, Field.PIZZA));
    }

    private static String bestGirls(final List<Friend> friends) {
        //List<Friend> newFriends = new ArrayList<>(friends);
        //Collections.sort(newFriends, new FriendComparator(Field.GIRLS));

        return joinNames(allMaxNames(friends, Field.GIRLS));
    }

    private static boolean isPizzaNumber(final String number) {
        List<Integer> digits = toIntArray(number);
        int prev = digits.get(0);

        for (int i = 1; i < digits.size(); i++) {
            if (digits.get(i) >= prev) {
                return false;
            }

            prev = digits.get(i);
        }

        return true;
    }

    private static boolean isTaxiNumber(final String number) {
        List<Integer> digits = toIntArray(number);
        int first = digits.get(0);

        for (int i = 1; i < digits.size(); i++) {
            if (first != digits.get(i)) {
                return false;
            }
        }

        return true;
    }

    private static List<Integer> toIntArray(final String number) {
        List<Integer> result = new ArrayList<>();

        for (char digit: number.toCharArray()) {
            if (digit != '-') {
                result.add(digit - '0');
            }
        }

        return result;
    }

    private static String joinNames(final List<String> names) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < names.size(); i++) {
            result.append(names.get(i));

            if (i + 1 < names.size()) {
                result.append(", ");
            }
        }

        return result.toString();
    }

    private static Integer getFieldValue(final Friend friend, final Field field) {
        if (field == Field.TAXI) {
            return friend.taxi;
        } else if (field == Field.PIZZA) {
            return friend.pizza;
        }

        return friend.girls;
    }

    private static List<String> allMaxNames(final List<Friend> friends, final Field field) {
        List<String> names = new ArrayList<>();
        //int maxValue = getFieldValue(friends.get(friends.size() - 1), field);
        //Stack<String> namesStack = new Stack<>();
        int maxValue = 0;

        for (int i = 0; i < friends.size(); i++) {
            maxValue = Math.max(maxValue, getFieldValue(friends.get(i), field));
        }

        for (int i = 0; i < friends.size(); i++) {
            if (getFieldValue(friends.get(i), field) == maxValue) {
                names.add(friends.get(i).name);
            }
        }

        //while ( ! namesStack.isEmpty()) {
        //    names.add(namesStack.pop());
        //}

        return names;
    }

    private enum Field {TAXI, PIZZA, GIRLS}

    private static class Friend {
        public final String name;
        public Integer taxi = 0, pizza = 0, girls = 0;

        public Friend(final String name) {
            this.name = name;
        }
    }

    /*private static class FriendComparator implements Comparator<Friend> {
        private final Field field;

        public FriendComparator(final Field field) {
            this.field = field;
        }

        public int compare(final Friend one, final Friend two) {
            return getFieldValue(one, this.field).compareTo(getFieldValue(two, this.field));
        }
    }*/
}
