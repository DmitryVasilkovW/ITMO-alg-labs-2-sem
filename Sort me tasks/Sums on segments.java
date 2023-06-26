import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
      
        int n = Integer.parseInt(reader.readLine());

       
        long[] a = new long[n + 1];
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 1; i <= n; i++) {
            a[i] = Long.parseLong(tokenizer.nextToken());
        }

      
        int m = Integer.parseInt(reader.readLine());

       
        for (int i = 0; i < m; i++) {
          
            tokenizer = new StringTokenizer(reader.readLine());
            int l = Integer.parseInt(tokenizer.nextToken());
            int r = Integer.parseInt(tokenizer.nextToken());

          
            if (l > r) {
                writer.write(0 + " ");
            } else {
               
                long sum = 0;
                for (int j = l; j <= r; j++) {
                    sum += a[j];
                }
                writer.write(sum + " ");
            }
        }

  
        reader.close();
        writer.flush();
        writer.close();
    }
}
