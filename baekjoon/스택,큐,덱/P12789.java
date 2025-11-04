import java.io.*;
import java.util.*;

public class P12789 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        Stack<Integer> stk = new Stack<>();
        

        int cur = 1;
        String ans = "Nice";

        for(int i = 0;i < n; i++){
            int num = Integer.parseInt(st.nextToken());
            
            if(stk.empty() || stk.peek() > num){
                stk.push(num);
                continue;
            } 

            while(stk.size() > 0 && stk.peek() < num){
                int popedNum = stk.pop();
                if(cur != popedNum) {
                    ans = "Sad";
                } else {
                    cur++;
                }
            }

            stk.push(num);
        }

        while(stk.size() > 0){
            if(cur != stk.peek()) {
                ans = "Sad";
                break;
            } 

            stk.pop();
            cur++;
        }

        System.out.println(ans);

    }
}
