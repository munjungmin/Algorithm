import java.io.*;
import java.util.*;

public class P11866 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        Queue<Integer> q = new LinkedList<>();

        for(int i = 1; i <= n; i++){
            q.add(i);
        }

        StringBuffer sb = new StringBuffer("<");
        
        while(q.size() > 1){
            int sum = 0;        

            while(++sum % k != 0){
                q.add(q.poll());
            }

            sb.append(q.poll() + ", ");
        }

        sb.append(q.poll() + ">");
        System.out.println(sb);
    }
}
