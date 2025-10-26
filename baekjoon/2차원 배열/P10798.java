import java.io.*;

public class P10798 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        char[][] arr = new char[5][];

        for(int i = 0; i < 5; i++){
            arr[i] = br.readLine().toCharArray();    
        }

        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 5; j++){
                if(i >= arr[j].length) continue;
                sb.append(arr[j][i]);
            }
        }
        
        System.out.println(sb);
    }    
}
