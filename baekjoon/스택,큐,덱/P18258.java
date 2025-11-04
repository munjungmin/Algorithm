import java.io.*;
import java.util.*;

public class P18258 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        LinkedList<Integer> q = new LinkedList<>();
        StringBuffer sb = new StringBuffer();

        while(n-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String input = st.nextToken();
            if(input.equals("push")){
                int num = Integer.parseInt(st.nextToken());
                q.add(num);
            }
            else if(input.equals("front")){
                sb.append(q.peekFirst() == null ? "-1" : q.peekFirst()).append("\n");
            } else if(input.equals("back")){
                sb.append(q.peekLast() == null ? "-1" : q.peekLast()).append("\n");
            } else if(input.equals("size")){
                sb.append(q.size()).append("\n");
            } else if(input.equals("empty")){
                sb.append(q.isEmpty() ? 1 : 0).append("\n");
            } else {
                Integer num = q.poll();
                sb.append(num == null ? -1 : num).append("\n");
            }
        }

        System.out.println(sb);
    }
}
