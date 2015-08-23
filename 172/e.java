import java.util.Scanner;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

public class e {

  private static BhtmlNode rootNode = new BhtmlNode(null);

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    List<String> tokens = new ArrayList<>();
    Stack<BhtmlNode> pathStack = new Stack<>();
    BhtmlNode currentNode = rootNode;

    for (String token: sc.nextLine().split("<|>")) {
      if (token.isEmpty()) {
        continue;
      }

      if (token.startsWith("/")) {
        currentNode = pathStack.pop();
        continue;
      }

      if ( ! token.endsWith("/")) {
        currentNode.children.add(new BhtmlNode(token));
        pathStack.push(currentNode);
        currentNode = currentNode.children.get(currentNode.children.size() - 1);
      } else {
        currentNode.children.add(new BhtmlNode(token.substring(0, token.length() - 1)));
      }
    }

    int m = Integer.parseInt(sc.nextLine());

    for (int i = 0; i < m; ++i) {
      System.out.println(rootNode.search(sc.nextLine().split("\\s"), 0));
    }

    sc.close();
  }

  private static class BhtmlNode {

    private String tag;
    public List<BhtmlNode> children = new ArrayList<>();

    public BhtmlNode(String tag) {
      this.tag = tag;
    }

    public int search(String[] query, int position) {
      int found = 0;

      if (this.tag != null && this.tag.equals(query[position])) {
        if (position + 1 == query.length) {
          ++found;
        } else {
          ++position;
        }
      }

      for (BhtmlNode child: this.children) {
        found += child.search(query, position);
      }

      return found;
    }
  }
}
