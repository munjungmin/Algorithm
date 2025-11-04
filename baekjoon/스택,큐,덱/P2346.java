import java.io.*;
import java.util.*;

public class P2346 {

    static class Pair{
        int x;
        int y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();

        Deque<Pair> dq = new ArrayDeque<>();
        
        for(int i = 0; i < n; i++){
            dq.add(new Pair(i+1,Integer.parseInt(st.nextToken())));
        }

        Pair pair = dq.pollFirst();
        sb.append(pair.x + " ");
        int num = pair.y;

        while(!dq.isEmpty()){

            while(num > 1){
                dq.add(dq.pollFirst());
                num--;
            }

            while(num < 0){
                dq.addFirst(dq.pollLast());
                num++;
            }
   
            pair = dq.pollFirst();
            sb.append(pair.x + " ");
            num = pair.y;
        }


        System.out.println(sb);
    }
}


