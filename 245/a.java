import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Server a = new Server(), b = new Server();

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            if (sc.nextInt() == 1) {
                a.addPacket(10, sc.nextInt());
            } else {
                b.addPacket(10, sc.nextInt());
            }

            sc.nextInt();
        }

        sc.close();

        System.out.println(a.isAlive() ? "LIVE" : "DEAD");
        System.out.println(b.isAlive() ? "LIVE" : "DEAD");
    }

    private static class Server {
        private int sent = 0, received = 0;

        public void addPacket(int sent, int received) {
            this.sent += sent;
            this.received += received;
        }

        public boolean isAlive() {
            return (this.sent / 2) <= this.received;
        }
    }
}
