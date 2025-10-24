import java.util.Scanner;

public class P9086 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();

        while(T > 0){
            String str = sc.nextLine();
            System.out.println(str.charAt(0) + "" +str.charAt(str.length()-1));
            T--;
        }
    }
}
