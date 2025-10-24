import java.util.Scanner;

public class P11720 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        String str = sc.next();
        int sum = 0;

        for(char c : str.toCharArray()){
            sum += (c - '0');
        }

        System.out.println(sum);
    }
}
