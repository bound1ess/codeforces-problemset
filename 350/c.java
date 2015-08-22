import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class c {

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    int n = Integer.parseInt(in.readLine());
    List<Bomb> bombs = new ArrayList<>();

    for (int i = 0; i < n; ++i) {
      String[] input = in.readLine().split("\\s");
      bombs.add(new Bomb(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
    }

    in.close();
    Collections.sort(bombs);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      ans += bombs.get(i).findDist();
    }

    out.write(Integer.toString(ans));
    out.newLine();

    for (int i = 0; i < n; ++i) {
      bombs.get(i).printPath(out);
    }

    out.close();
  }
}

class Bomb implements Comparable<Bomb> {

  public int x, y;

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
    if (this.x != 0) {
      out.write("1 " + Math.abs(this.x) + " " + (this.x > 0 ? 'R' : 'L'));
      out.newLine();
    }

    if (this.y != 0) {
      out.write("1 " + Math.abs(this.y) + " " + (this.y > 0 ? 'U' : 'D'));
      out.newLine();
    }

    out.write("2");
    out.newLine();

    if (this.x != 0) {
      out.write("1 " + Math.abs(this.x) + " " + (this.x > 0 ? 'L' : 'R'));
      out.newLine();
    }

    if (this.y != 0) {
      out.write("1 " + Math.abs(this.y) + " " + (this.y > 0 ? 'D' : 'U'));
      out.newLine();
    }

    out.write("3");
    out.newLine();
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
