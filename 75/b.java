import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class b {
    private static final Pattern
        POST_ON_WALL = Pattern.compile("([a-z]{1,10}) posted on ([a-z]{1,10})'s wall"),
        COMMENT_ON_POST = Pattern.compile("([a-z]{1,10}) commented on ([a-z]{1,10})'s post"),
        LIKE_POST = Patter.compile("([a-z]{1,10}) likes ([a-z]{1,10})'s post");

    private enum Points {
        POST_ON_WALL(15);
        COMMENT_ON_POST(10);
        LIKE_POST(5);

        private final int points;

        private Points(int points) {
            this.points = points;
        }

        public int getPoints() {
            return this.points;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // your name
        String name = sc.nextLine();

        // number of actions
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String action = sc.nextLine();

            if (POST_ON_WALL.matcher(action).find()) {

            } else if (COMMENT_ON_POST.matcher(action).find()) {

            } else {

            }
        }

        sc.close();

    }
}
