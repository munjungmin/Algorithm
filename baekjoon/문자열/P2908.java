import java.util.Scanner;

public class P2908 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();
        String ans = null;

        for(int i = 2; i >= 0; i--){
            if(a.charAt(i) > b.charAt(i)){
                ans = a;
                break;
            } else if (a.charAt(i) < b.charAt(i)){
                ans = b;
                break;
            }
        }

        System.out.println(new StringBuilder(ans).reverse());

    }
}
