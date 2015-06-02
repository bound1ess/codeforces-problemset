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
            //if (path.equals("stop")) break;
            addPath(path);
        }

        sc.close();

        int maxFiles = 0, maxFolders = 0;

        for (Entry<String, Folder> entry: root.entrySet()) {
            maxFiles = Math.max(maxFiles, entry.getValue().getFiles());
            maxFolders = Math.max(maxFolders, entry.getValue().getFolders());
        }

        System.out.println(maxFolders + " " + maxFiles);
    }

    private static void addPath(final String path) {
        //String diskName = path.substring(0, 1);
        //String[] parts = path.substring(3).split("\\\\");
        int start = path.indexOf('\\', 3);
        String diskName = path.substring(0, start);
        String[] parts = path.substring(start + 1).split("\\\\");

        //System.out.println(path.substring(0, path.indexOf('\\', 3)));
        //System.out.println(path.substring(path.indexOf('\\', 3) + 1));

        if (root.containsKey(diskName)) {
            root.get(diskName).add(parts, 0);
        } else {
            Folder folder = new Folder();
            folder.add(parts, 0);

            root.put(diskName, folder);
        }
    }
}

class Folder {
    private int files = 0, folders = 0;
    private final Map<String, Folder> children = new HashMap<>();

    public int add(final String[] path, int start) {
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

        this.files++;
        this.folders += foldersCount;

        return foldersCount;
    }

    public int getFiles() {
        return this.files;
    }

    public int getFolders() {
        return this.folders;
    }
}
