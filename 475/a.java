import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;

public class a {
    private final static int ROW = 11, SHORT_ROW = 1, ROWS = 4, SHORT_ROW_INDEX = 2;

    public static void main(final String[] arguments) {
        int k = new Scanner(System.in).nextInt();
        List<Entry<Integer, List<Boolean>>> bus = createBus();

        int lastPlaced = -1;

        for (int i = 0; i < k; i++) {
            int j = 0;

            if (lastPlaced + 1 == ROWS) {
                lastPlaced = -1;
            }

            for (Entry<Integer, List<Boolean>> row: bus) {
                if (row.getKey() != row.getValue().size() && j > lastPlaced) {
                    row.getValue().add(true);
                    lastPlaced = j;
                    //System.out.println("last placed now is " + lastPlaced);

                    break;
                }

                j++;
            }
        }

        //for (Entry<Integer, List<Boolean>> row: bus) {
        //    System.out.println(row.getKey() + ", " + row.getValue().size());
        //}

        // print the result
        String border = "+------------------------+";
        String[] endWith = {"|D|)", "|.|", "..|", "|.|)"};

        System.out.println(border);

        for (int i = 0; i < ROWS; i++) {
            System.out.print('|');

            int rowLength = bus.get(i).getValue().size();
            int rowCapacity = bus.get(i).getKey();

            for (int j = 0; j < rowLength; j++) {
                System.out.print("O.");
            }

            for (int j = 0; j < (rowCapacity - rowLength); j++) {
                System.out.print("#.");
            }

            if (rowCapacity == SHORT_ROW) {
                for (int j = 0; j < (ROW - SHORT_ROW) * 2; j++) {
                    System.out.print('.');
                }
            }

            System.out.println(endWith[i]);
        }

        System.out.println(border);
    }

    private static List<Entry<Integer, List<Boolean>>> createBus() {
        List<Entry<Integer, List<Boolean>>> bus = new ArrayList<>();

        for (int i = 0; i < ROWS; i++) {
            bus.add(
                new SimpleEntry<Integer, List<Boolean>>(
                    (i == SHORT_ROW_INDEX ? SHORT_ROW : ROW), new ArrayList<Boolean>()
                )
            );
        }

        return bus;
    }
}
