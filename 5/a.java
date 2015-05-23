import java.util.Scanner;
//import java.util.ArrayList;

public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int members = 0, sent = 0;

        while (in.hasNextLine()) {
            String cmd = in.nextLine();

            //if (cmd.equals("down")) {
            //    break;
            //}

            if (cmd.charAt(0) == '+') {
                members++;
            } else if (cmd.charAt(0) == '-') {
                members--;
            } else {
                String[] msg = cmd.split(":");
                int size = msg.length > 1 ? msg[1].length() : 0;
                //System.out.println("Sending msg of size " + size + " to "+members+" users.");
                sent += size * members;
            }
        }

        in.close();
        System.out.println(sent);
    }
}
