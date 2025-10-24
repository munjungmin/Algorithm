import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1546 {
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        double arr[] = new double[N];
        
        // max
        double M = -1;
        for(int i = 0; i < N; i++){
            arr[i] = Double.parseDouble(st.nextToken());
            if(arr[i] > M) M = arr[i];
        }
        
        double sum = 0;
        for(int i = 0; i < N; i++){
            arr[i] = arr[i] / M * 100;
            sum += arr[i];
        }

        System.out.println(sum / N);

    }
}
