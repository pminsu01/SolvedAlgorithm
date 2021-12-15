import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());

        while (testcase-- > 0) {

            String line;
            int[] use = new int[9];
            int max = Integer.parseInt(br.readLine());
            String[] use_con = new String[9];
            int sum = 0;
            use_con = br.readLine().split(" ");

            for (int i = 0; i < use_con.length; i++) {

                use[i] = Integer.parseInt(use_con[i]);

            }


            for (int j = 0; j < use.length; j++) {

                sum += use[j];

            }


            if (sum > max) {

                System.out.println("NO");
            } else System.out.println("YES");


        }


    }
}
