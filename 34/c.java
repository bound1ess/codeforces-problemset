import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class c {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] input = in.nextLine().split(",");
        in.close();

        ArrayList<Integer> nums = new ArrayList<>();

        for (int i = 0; i < input.length; i++) {
            int value = Integer.parseInt(input[i]);
            //System.out.println("Parsed " + value);

            if (nums.indexOf(value) < 0) {
                //System.out.println("Added " + value);
                nums.add(value);
            }
        }

        Collections.sort(nums);

        //for (int i = 0; i < nums.size(); i++)
        //    System.out.println(nums.get(i));

        for (int i = 0; i < nums.size(); i++) {
            int streak = 1, j = i;

            while (j + 1 < nums.size() && nums.get(j) + 1 == nums.get(j + 1)) {
                j++;
                streak++;
            }

            if (streak > 1) {
                System.out.print(nums.get(i) + "-" + nums.get(j));
            } else {
                System.out.print(nums.get(i));
            }

            if (j + 1 < nums.size()) {
                System.out.print(",");
            }

            i = j;
        }

        System.out.println("");
    }
}
