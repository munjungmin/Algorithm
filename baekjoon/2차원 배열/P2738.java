import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class P2738 {
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int arr[][][] = new int[2][N][M];
        

        for(int k = 0; k < 2; k++){
            for(int i = 0; i < N; i++){
                
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < M; j++){
                    arr[k][i][j] = Integer.parseInt(st.nextToken());
                }
            }
        }

        // 덧셈 
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int sum = arr[0][i][j] + arr[1][i][j];
                sb.append(sum).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);

    }
}
