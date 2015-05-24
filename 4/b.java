import java.util.Scanner;

public class b {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int d = in.nextInt(), sumTime = in.nextInt();
        int minSum = 0, maxSum = 0;
        int[] min = new int[d], max = new int[d];

        for (int i = 0; i < d; i++) {
            min[i] = in.nextInt();
            max[i] = in.nextInt();
            minSum += min[i];
            maxSum += max[i];
        }

        in.close();

        if (minSum > sumTime || maxSum < sumTime) {
            System.out.println("NO");
            return;
        }

        int fill = 0;

        while (minSum != sumTime) {
            while (min[fill] == max[fill]) {
                fill++;
            }

            min[fill]++;
            minSum++;
        }

        System.out.println("YES");

        for (int i = 0; i < d; i++) {
            System.out.print(min[i] + " ");
        }

        System.out.println("");
    }
}
