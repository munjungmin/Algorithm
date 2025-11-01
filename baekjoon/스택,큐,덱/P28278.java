import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class P28278 {
    public static void main(String[] args) throws IOException{
        Stack<Integer> stk = new Stack<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());

            if(cmd == 1){
                stk.push(Integer.parseInt(st.nextToken()));
            }
            else if(cmd == 2){
                if(stk.isEmpty()){
                    sb.append(-1 + "\n");
                }else {

                    sb.append(stk.pop() + "\n");
                }
            }
            else if(cmd == 3){
                sb.append(stk.size() + "\n");
            }
            else if(cmd == 4){
                if(stk.isEmpty()){
                    sb.append(1 + "\n");
                } else {
                    sb.append(0 + "\n");
                }
            } else {
                if(stk.size() > 0)
                    sb.append(stk.peek() + "\n");
                else {
                    sb.append(-1 + "\n");
                }
            }            
        }
        System.out.println(sb);
    }
}

// java Stack은 비어있는 경우 pop() 혹은 peek()을 할때 예외가 발생하므로 주의 