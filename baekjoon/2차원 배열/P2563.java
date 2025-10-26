import java.io.*;
import java.util.*;

public class P2563 {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int arr[][] = new int[100][100];

        int N = sc.nextInt();
        int a, b;
        for(int i = 0; i < N; i++){
            a = sc.nextInt();
            b = sc.nextInt();

            for(int p = a; p < a + 10; p++){
                for(int q = b; q < b + 10; q++){
                    arr[p][q] = 1;
                }
            }
        }

        int answer = 0;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                answer += arr[i][j];
            }
        }

        System.out.println(answer);

    }    
}
