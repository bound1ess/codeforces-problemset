import java.util.Scanner;

public class b {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String code = sc.nextLine();
        sc.close();

        StringBuilder answer = new StringBuilder();

        for (int i = 0; i < code.length(); i++) {
            if (code.charAt(i) == '.') {
                answer.append('0');
                continue;
            }

            if (code.charAt(i + 1) == '-') {
                answer.append('2');
            } else {
                answer.append('1');
            }

            i++;
        }

        System.out.println(answer.toString());
    }
}
