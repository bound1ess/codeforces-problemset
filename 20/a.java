public class a {
    public static void main(final String[] args) {
        String path = new java.util.Scanner(System.in).nextLine().replaceAll("/{2,}", "/");
        if (path.length() == 1) {
            System.out.println(path);
            return;
        }
        System.out.println(path.endsWith("/") ? path.substring(0, path.length() - 1) : path);
    }
}
