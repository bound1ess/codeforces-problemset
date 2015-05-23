import java.util.Scanner;
import java.util.HashMap;
import java.math.BigInteger;

public class b {
    private static final int MOD = 1000003;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String expr = in.nextLine();
        in.close();

        HashMap<Character, String> cmds = new HashMap<>();

        cmds.put('>', "1000");
        cmds.put('<', "1001");
        cmds.put('+', "1010");
        cmds.put('-', "1011");
        cmds.put('.', "1100");
        cmds.put(',', "1101");
        cmds.put('[', "1110");
        cmds.put(']', "1111");

        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < expr.length(); i++) {
            ans.append(cmds.get(expr.charAt(i)));
        }

        System.out.println(
            new BigInteger(ans.toString(), 2).remainder(BigInteger.valueOf(MOD))
        );
    }
}
