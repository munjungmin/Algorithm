import java.io.*;
import java.util.*;

public class P1764 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Set<String> set = new HashSet<>();
        Set<String> ansSet = new TreeSet<>();
        for(int i = 0; i < n; i++){
            set.add(br.readLine());
        }

        int answer = 0;
        for(int i = 0; i < m; i++){
            String input = br.readLine();
            if(set.contains(input)){
                answer++;
                ansSet.add(input);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(String str : ansSet){
            sb.append(str).append("\n");
        }
        
        System.out.println(answer);
        System.out.println(sb);
    }    
}
