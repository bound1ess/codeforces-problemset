import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

import java.util.List;
import java.util.ArrayList;
import java.util.TreeSet;

public class b {
    private static final int N = 26;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] numbers = reader.readLine().split("\\s");
        int n = Integer.parseInt(numbers[0]), k = Integer.parseInt(numbers[1]);
        List<String> addrs = new ArrayList<>(n);
        List<TreeSet<Integer>> chars = new ArrayList<>(N);
        String addr = reader.readLine();

        for (int i = 0; i < n; i++) {
            addrs.add(reader.readLine());
        }

        for (int i = 0; i < N; i++) {
            chars.add(new TreeSet<Integer>());
        }

        for (int i = 0; i < k; i++) {
            chars.get(addr.charAt(i) - 'a').add(i);
        }

        reader.close();

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 0; i < n; i++) {
            int length = addrs.get(i).length();
            long answer = 0;

            for (int j = 0; j < length; j++) {
                Integer floor = chars.get(addrs.get(i).charAt(j) - 'a').floor(j);
                Integer ceil = chars.get(addrs.get(i).charAt(j) - 'a').ceiling(j);

                int dist1 = (null == floor) ? Integer.MAX_VALUE : (j - floor);
                int dist2 = (null == ceil) ? Integer.MAX_VALUE : (ceil - j);

                if (Math.min(dist1, dist2) == Integer.MAX_VALUE) {
                    answer += length;
                } else {
                    answer += Math.min(dist1, dist2);
                }
            }

            writer.write(answer + "\n");
        }

        writer.close();
    }
}
