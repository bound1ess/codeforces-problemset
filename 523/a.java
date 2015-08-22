import java.util.Scanner;

public class a {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int w = sc.nextInt(), h = sc.nextInt();
    String[] img = new String[h];

    for (int i = 0; i < h; ++i) {
      img[i] = sc.next();
    }

    sc.close();
    String[] newImg = zoom(flip(rotate(img)));

    for (int i = 0; i < newImg.length; ++i) {
      System.out.println(newImg[i]);
    }
  }

  private static String[] rotate(String[] img) {
    int w = img[0].length();
    String[] newImg = new String[w];

    for (int i = 0; i < w; ++i) {
      StringBuilder newLine = new StringBuilder();

      for (int j = img.length - 1; j >= 0; --j) {
        newLine.append(img[j].charAt(i));
      }

      newImg[i] = newLine.toString();
    }

    return newImg;
  }

  private static String[] flip(String[] img) {
    String[] newImg = new String[img.length];

    for (int i = 0; i < img.length; ++i) {
      int l = 0, r = img[i].length() - 1;
      StringBuilder newLine = new StringBuilder(img[i]);

      while (l < r) {
        char tmp = img[i].charAt(l);
        newLine.setCharAt(l, img[i].charAt(r));
        newLine.setCharAt(r, tmp);
        l++;
        r--;
      }

      newImg[i] = newLine.toString();
    }

    return newImg;
  }

  private static String[] zoom(String[] img) {
    String[] newImg = new String[img.length * 2];
    int k = 0;

    for (int i = 0; i < img.length; ++i) {
      for (int j = 0; j < 2; ++j) {
        newImg[k] = zoomLine(img[i]);
        ++k;
      }
    }

    return newImg;
  }

  private static String zoomLine(String line) {
    StringBuilder newLine = new StringBuilder();

    for (char chr: line.toCharArray()) {
      newLine.append(chr);
      newLine.append(chr);
    }

    return newLine.toString();
  }
}
