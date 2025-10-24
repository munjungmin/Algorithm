import java.util.Scanner;

public class P5622 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        String dial[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

        int answer = 0;

        for(char c : str.toCharArray()){
            for(int i = 0; i < dial.length; i++) {
                if(dial[i].indexOf(c) != -1){
                    answer += i + 3;
                    break;
                }
            }       
        }

        System.out.println(answer);

    }
}
