import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class c {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(in.readLine());
        ArrayList<Bomb> bombs = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] input = in.readLine().split("\\s");
            bombs.add(new Bomb(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
        }

        in.close();

        Collections.sort(bombs);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            //out.write("(" + bombs.get(i).x + ", " + bombs.get(i).y + ")\n");
            ans += bombs.get(i).findDist();
        }

        out.write(ans + "\n");

        for (int i = 0; i < n; i++) {
            bombs.get(i).printPath(out);
        }

        out.close();
    }
}

class Bomb implements Comparable<Bomb> {
    public final int x, y;

    public Bomb(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int findDist() {
        int dist = 2;

        if (this.x != 0) {
            dist += 2;
        }

        if (this.y != 0) {
            dist += 2;
        }

        return dist;
    }

    public void printPath(final BufferedWriter out) throws IOException {
        // Get to the bomb.
        if (this.x != 0) {
            out.write("1 " + Math.abs(this.x) + " " + (this.x > 0 ? 'R' : 'L') + "\n");
        }

        if (this.y != 0) {
            out.write("1 " + Math.abs(this.y) + " " + (this.y > 0 ? 'U' : 'D') + "\n");
        }

        out.write("2\n");

        if (this.x != 0) {
            out.write("1 " + Math.abs(this.x) + " " + (this.x > 0 ? 'L' : 'R') + "\n");
        }

        if (this.y != 0) {
            out.write("1 " + Math.abs(this.y) + " " + (this.y > 0 ? 'D' : 'U') + "\n");
        }

        out.write("3\n");
    }

    public int compareTo(Bomb bomb) {
        int dist = Math.abs(this.x) + Math.abs(this.y);
        int bombDist = Math.abs(bomb.x) + Math.abs(bomb.y);

        if (dist == bombDist) {
            return 0;
        }

        return dist < bombDist ? -1 : 1;
    }
}
