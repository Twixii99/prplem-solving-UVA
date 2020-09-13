import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt(), y = scanner.nextInt(), z = scanner.nextInt();
        int[][][] arr = new int[x+1][y+1][z+1];
        for(int i = 1; i <= x; ++i) {
            for(int j = 1; j <= y; ++j) {
                for(int k = 1; k <= z; ++k) {
                    arr[i][j][k] = scanner.nextInt();
                }
            }
        }

        for(int i = 1; i <= x; ++i) {
            for(int j = 1; j <= y; ++j) {
                for(int k = 1; k <= z; ++k) {
                    arr[i][j][k] += arr[i][j][k-1];
                }
            }
        }

        for(int i = 1; i <= x; ++i) {
            for(int k = 1; k <= z; ++k) {
                for(int j = 1; j <= y; ++j) {
                    arr[i][j][k] += arr[i][j-1][k];
                }
            }
        }

        for(int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                for (int k = 1; k <= z; ++k) {
                    arr[i][j][k] += arr[i-1][j][k];
                }
            }
        }

        int x1 = scanner.nextInt(), y1 = scanner.nextInt(), z1 = scanner.nextInt(),
                x2 = scanner.nextInt(), y2 = scanner.nextInt(), z2 = scanner.nextInt();

        System.out.println(arr[x1][y1][z1] - arr[x1][y2-1][z1] - arr[x2-1][y1][z1] - arr[x1][y1][z2-1]  +
                arr[x2-1][y2-1][z1] + arr[x1][y2-1][z2-1] + arr[x2-1][y1][z2-1] - arr[x2-1][y2-1][z2-1]);
    }
}
