import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;

public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();

        HashMap<String, Integer> game = new HashMap<>();
        String[] players = new String[n];
        int[] score = new int[n];

        for (int i = 0; i < n; i++) {
            String[] input = in.nextLine().split("\\s");
            String name = input[0];
            int givenScore = Integer.parseInt(input[1]);

            players[i] = name;
            score[i] = givenScore;

            if ( ! game.containsKey(name)) {
                game.put(name, givenScore);
            } else {
                game.put(name, game.get(name) + givenScore);
            }
        }

        in.close();

        int maxScore = -1000001;

        for (Integer playerScore: game.values()) {
            maxScore = Math.max(maxScore, playerScore);
        }

        ArrayList<String> winners = new ArrayList<>();

        for (String playerName: game.keySet()) {
            if (game.get(playerName) == maxScore) {
                winners.add(playerName);
            }
        }

        if (2 > winners.size()) {
            System.out.println(winners.get(0));
            return;
        }

        game.clear();

        for (int i = 0; i < n; i++) {
            if (winners.indexOf(players[i]) < 0) {
                continue;
            }

            if ( ! game.containsKey(players[i])) {
                game.put(players[i], score[i]);
            } else {
                game.put(players[i], game.get(players[i]) + score[i]);
            }

            if (maxScore <= game.get(players[i])) {
                System.out.println(players[i]);
                return;
            }
        }
    }
}
