import java.io.*;
import java.util.*;

public class P7785 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Set<String> s = new TreeSet<>(Collections.reverseOrder());

        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String log = st.nextToken();

            if(log.equals("enter")){
                s.add(name);
            } else {
                s.remove(name);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(String str : s){
            sb.append(str).append("\n");
        }
     
        System.out.println(sb);
    }    
}
