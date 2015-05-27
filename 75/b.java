import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;
import java.util.Comparator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class b {
    private static final Pattern regex
        = Pattern.compile("([a-z]+) (posted on|commented on|likes) ([a-z]+)'s (wall|post)");

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // your name
        String name = sc.nextLine();

        HashMap<String, Integer> priorities = new HashMap<>();

        // number of actions
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<String> tmp = new ArrayList<>(2);

        for (int i = 0; i < n; i++) {
            String action = sc.nextLine();
            Matcher match = regex.matcher(action);
            match.find();

            int priority;

            if (match.group(2).equals("posted on")) {
                priority = 15;
            } else if (match.group(2).equals("commented on")) {
                priority = 10;
            } else {
                priority = 5;
            }

            tmp.clear();

            if (name.equals(match.group(1)) || name.equals(match.group(3))) {
                tmp.add(name.equals(match.group(1)) ? match.group(3) : match.group(1));
            } else {
                priority = 0;

                tmp.add(match.group(1));
                tmp.add(match.group(3));
            }

            for (String person: tmp) {
                if ( ! priorities.containsKey(person)) {
                    priorities.put(person, priority);
                } else {
                    priorities.put(person, priorities.get(person) + priority);
                }
            }
        }

        sc.close();

        ArrayList<Entry<String, Integer>> personList = new ArrayList<>();

        for (String personName: priorities.keySet()) {
            personList.add(
                new SimpleEntry<String, Integer>(personName, priorities.get(personName))
            );
        }

        Collections.sort(personList, new PriorityComparator());

        for (Entry<String, Integer> person: personList) {
            System.out.println(person.getKey());
        }
    }
}

class PriorityComparator implements Comparator<Entry<String, Integer>> {

    public int compare(Entry<String, Integer> one, Entry<String, Integer> two) {
        if (one.getValue() == two.getValue()) {
            return one.getKey().compareTo(two.getKey());
        }

        return one.getValue() > two.getValue() ? -1 : 1;
    }
}
