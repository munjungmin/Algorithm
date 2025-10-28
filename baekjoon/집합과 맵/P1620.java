import java.io.*;
import java.util.*;

public class P1620 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Map<Integer, String> map = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();

        for(int i = 0; i < n; i++){
            String input = br.readLine();
            map.put(i+1, input);
            map2.put(input, i+1);
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < m; i++){
            String input = br.readLine();
            try{
                int num = Integer.parseInt(input);
                sb.append(map.get(num)).append("\n");
            } catch (NumberFormatException e){
                sb.append(map2.get(input)).append("\n");
            }
        }
        System.out.println(sb);
    }
}
 //Character.isDigit(input.charAt(0))
 //input.matches("[0-9]+")