import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BOJ_30802 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < 6; i++) {
            list.add(sc.nextInt());
        }

        int t = sc.nextInt();
        int p = sc.nextInt();

        int a = 0, b = 0, c = 0;
        for (int i : list) {
            a += i / t;
            a += (i % t) > 0 ? 1 : 0;
        }

        b = n / p;
        c = n % p;

        System.out.println(a);
        System.out.println(b + " " + c);
    }
}
