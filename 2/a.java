import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class a {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = Integer.parseInt(in.nextLine());
    Map<String, Integer> game = new HashMap<>();
    String[] players = new String[n];
    int[] score = new int[n];

    for (int i = 0; i < n; ++i) {
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
    int maxScore = -Integer.MAX_VALUE;
    List<String> winners = new ArrayList<>();

    for (Integer playerScore: game.values()) {
      maxScore = Math.max(maxScore, playerScore);
    }

    for (String playerName: game.keySet()) {
      if (game.get(playerName) == maxScore) {
        winners.add(playerName);
      }
    }

    if (winners.size() == 1) {
      System.out.println(winners.get(0));
      return;
    }

    game.clear();

    for (int i = 0; i < n; ++i) {
      if (winners.indexOf(players[i]) == -1) {
        continue;
      }

      if ( ! game.containsKey(players[i])) {
        game.put(players[i], score[i]);
      } else {
        game.put(players[i], game.get(players[i]) + score[i]);
      }

      if (maxScore <= game.get(players[i])) {
        System.out.println(players[i]);
        break;
      }
    }
  }
}
