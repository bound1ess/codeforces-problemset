import java.util.Scanner;

public class b {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String addr = in.nextLine();
    StringBuilder newAddr = new StringBuilder();
    in.close();

    if (addr.substring(0, 3).equals("ftp")) {
      newAddr.append("ftp://");
      addr = addr.substring(3);
    } else {
      newAddr.append("http://");
      addr = addr.substring(4);
    }

    int pivot = addr.indexOf("ru", 1);
    newAddr.append(addr.substring(0, pivot));
    newAddr.append(".ru");

    if (addr.length() > pivot + 2) {
      newAddr.append("/");
      newAddr.append(addr.substring(pivot + 2));
    }

    System.out.println(newAddr.toString());
  }
}
