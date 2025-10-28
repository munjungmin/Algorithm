import java.io.*;
import java.util.*;

public class P10816 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        Map<Integer, Integer> map = new HashMap<>();
        
        while(st.hasMoreTokens()){
            int num = Integer.parseInt(st.nextToken());
            map.put(num, map.getOrDefault(num, 0)+1);
        }

     
        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        while(st.hasMoreTokens()){
            int num = Integer.parseInt(st.nextToken());
            sb.append(map.getOrDefault(num, 0)).append(" ");
        }

        System.out.println(sb);
    }    
}
