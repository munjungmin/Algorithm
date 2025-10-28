import java.io.*;
import java.util.*;

public class P1269 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int lenA = Integer.parseInt(st.nextToken());
        int lenB = Integer.parseInt(st.nextToken());

        Set<Integer> a = new HashSet<>();
        
        st = new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
            a.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
            int num = Integer.parseInt(st.nextToken());
            if(a.contains(num)){
                lenA--;
                lenB--;
            }
        }

        System.out.println(lenA + lenB);
    }    
}
