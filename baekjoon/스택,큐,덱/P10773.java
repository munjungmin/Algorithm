import java.io.*;
import java.util.*;

public class P10773 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stk = new Stack<>();

        int k = Integer.parseInt(br.readLine());

        for(int i = 0; i < k; i++){
            int num = Integer.parseInt(br.readLine());
            if(num == 0){
                stk.pop();
            } else {
                stk.push(num);
            }
        }
        
        int sum = 0;
        for(int n : stk){
            sum += n;
        }
        System.out.println(sum);
    }
}
