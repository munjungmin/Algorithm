import java.io.*;
import java.util.*;

public class P9012 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while(t-- > 0){
            String input = br.readLine();
            Stack<Character> stk = new Stack<>();
            boolean flag = true;

            for(char ch : input.toCharArray()){
                if(ch == '('){
                    stk.push(ch);
                } else {
                    if(stk.isEmpty()){
                        flag = false;
                        break;
                    }

                    stk.pop();
                }
            }

            if(stk.isEmpty() == false){
                flag = false;
            }

            System.out.println(flag ? "YES" : "NO");

        }

    }
}
