import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class P1152 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine().trim();
        int answer = 0;        
    
        for(char c : str.toCharArray()){
            if(c == ' ') answer++;
        }
        
        if (!str.equals("")) {
            answer++;
        }
        System.out.println(answer);
    }
}
