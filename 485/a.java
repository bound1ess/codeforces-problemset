public class a {

    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int a = sc.nextInt(), m = sc.nextInt();
        sc.close();

        for (int i = 0; i <= m; i++) {
            a = (a * 2) % m;
        }

        System.out.println(a == 0 ? "Yes" : "No");
    }
}
