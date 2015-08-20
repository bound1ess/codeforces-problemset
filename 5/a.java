import java.util.Scanner;

public class a {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int members = 0, sent = 0;

    while (in.hasNextLine()) {
      String cmd = in.nextLine();

      if (cmd.charAt(0) == '+') {
        ++members;
      } else if (cmd.charAt(0) == '-') {
        --members;
      } else {
        String[] msg = cmd.split(":");
        int size = msg.length > 1 ? msg[1].length() : 0;
        sent += size * members;
      }
    }

    in.close();
    System.out.println(sent);
  }
}
