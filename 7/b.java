import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;

public class b {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int commands = sc.nextInt(), memorySize = sc.nextInt();
        int[] usedMemory = new int[memorySize];
        Set<Integer> allocated = new HashSet<Integer>();
        int freePointer = 1;

        for (int i = 0; i < commands; i++) {
            String nextCommand = sc.next();

            if (nextCommand.equals("defragment")) {
                defragment(usedMemory);
                continue;
            }

            if (nextCommand.equals("alloc")) {
                if (allocate(usedMemory, freePointer, sc.nextInt())) {
                    allocated.add(freePointer);
                    System.out.println(freePointer);
                    freePointer++;
                } else {
                    System.out.println("NULL");
                }
            } else {
                int blockId = sc.nextInt();

                if (allocated.contains(blockId)) {
                    erase(usedMemory, blockId);
                    allocated.remove(blockId);
                } else {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                }
            }
        }

        sc.close();
    }

    private static void erase(int[] memory, int blockId) {
        int i = 0;

        for (int block: memory) {
            if (block == blockId) {
                memory[i] = 0;
            }

            i++;
        }
    }

    private static boolean allocate(int[] memory, int pointer, int blockSize) {
        int streak = 0, i = 0;

        for (int block: memory) {
            if (block < 1) {
                streak++;
            } else {
                streak = 0;
            }

            if (streak == blockSize) {
                for (int j = 0; j < blockSize; j++) {
                    memory[i - j] = pointer;
                }

                return true;
            } else {
                i++;
            }
        }

        return false;
    }

    private static void defragment(int[] memory) {
        Queue<Integer> nonEmpty = new LinkedList<>();

        for (int block: memory) {
            if (block > 0) {
                nonEmpty.add(block);
            }
        }

        int pointer = 0;

        while ( ! nonEmpty.isEmpty()) {
            memory[pointer] = nonEmpty.poll();
            pointer++;
        }

        while (pointer < memory.length) {
            memory[pointer] = 0;
            pointer++;
        }
    }
}
