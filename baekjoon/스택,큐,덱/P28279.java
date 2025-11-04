import java.io.*;
import java.util.*;

public class P28279 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        Deque<Integer> dq = new LinkedList<>();
        StringBuffer sb = new StringBuffer();

        while(n-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            switch (num) {
                case 1 : dq.addFirst(Integer.parseInt(st.nextToken())); break;
                case 2 : dq.addLast(Integer.parseInt(st.nextToken())); break;
                case 3 : {
                    Integer polledNum = dq.pollFirst();
                    sb.append(polledNum == null ? -1 : polledNum).append("\n");
                    break;
                }
                case 4 : {
                    Integer polledNum = dq.pollLast();
                    sb.append(polledNum == null ? -1 : polledNum).append("\n");
                    break;
                }
                case 5 : sb.append(dq.size() + "\n"); break;
                case 6 : sb.append(dq.isEmpty() ? 1 : 0).append("\n"); break;
                case 7 : sb.append(dq.peekFirst() == null ? -1 : dq.peekFirst()).append("\n"); break;
                default : sb.append(dq.peekLast() == null ? -1 : dq.peekLast()).append("\n"); break;
            }
        }
        System.out.println(sb);
    }    
}
