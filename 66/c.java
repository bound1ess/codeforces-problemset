import java.util.Scanner;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;

public class c {

  private static final Map<String, Folder> root = new HashMap<>();

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    while (sc.hasNextLine()) {
      String path = sc.nextLine();
      addPath(path);
    }

    sc.close();
    int maxFiles = 0, maxFolders = 0;

    for (Entry<String, Folder> entry: root.entrySet()) {
      maxFiles = Math.max(maxFiles, entry.getValue().files);
      maxFolders = Math.max(maxFolders, entry.getValue().folders);
    }

    System.out.println(maxFolders + " " + maxFiles);
  }

  private static void addPath(String path) {
    int start = path.indexOf('\\', 3);
    String diskName = path.substring(0, start);
    String[] parts = path.substring(start + 1).split("\\\\");

    if (root.containsKey(diskName)) {
      root.get(diskName).add(parts, 0);
    } else {
      Folder folder = new Folder();
      folder.add(parts, 0);
      root.put(diskName, folder);
    }
  }

  private static class Folder {

    public int files = 0, folders = 0;
    private Map<String, Folder> children = new HashMap<>();

    public int add(String[] path, int start) {
      int foldersCount = 0;

      if (path.length > start + 1) {
        if (this.children.containsKey(path[start])) {
          foldersCount = this.children.get(path[start]).add(path, start + 1);
        } else {
          Folder folder = new Folder();
          foldersCount = folder.add(path, start + 1) + 1;
          this.children.put(path[start], folder);
        }
      }

      ++this.files;
      this.folders += foldersCount;

      return foldersCount;
    }
  }
}
