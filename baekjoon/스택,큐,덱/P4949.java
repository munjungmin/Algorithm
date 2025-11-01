import java.io.*;
import java.util.*;

public class P4949 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String str = br.readLine();
            if(str.equals(".")) break;

            Stack<Character> stk = new Stack<>();
            boolean flag = true;


            for(char ch : str.toCharArray()){
                if(ch == '(' || ch == '[') {
                    stk.push(ch);
                } else if(ch ==')') {
                    if(!stk.isEmpty() && stk.peek() == '('){
                        stk.pop();
                    } else {
                        flag = false;
                    }
                } else if(ch == ']'){
                    if(!stk.isEmpty() && stk.peek() == '['){
                        stk.pop();
                    } else {
                        flag = false;
                    }
                }
            }

            if(stk.isEmpty() == false){
                flag = false;
            }

            System.out.println(flag ? "yes" : "no");
        }

    }
}
