public class a {

    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int n = sc.nextInt();
        //int[] a = new int[n];
        int odd = 0, even = 0, lastOdd = 0, lastEven = 0;

        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();

            if (val % 2 == 0) {
                even++;
                lastEven = i;
            } else {
                odd++;
                lastOdd = i;
            }
        }

        sc.close();
        System.out.println(odd > even ? (lastEven + 1) : (lastOdd + 1));
    }
}
