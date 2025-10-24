import java.util.Scanner;

public class P2675 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T > 0){
            T--;

            int R = sc.nextInt();
            String str = sc.next();

            StringBuilder answer = new StringBuilder();
            for(char c : str.toCharArray()){
                for(int i = 0; i < R; i++){
                    answer.append(c);
                }
            }
            System.out.println(answer);
        }
    }
}
