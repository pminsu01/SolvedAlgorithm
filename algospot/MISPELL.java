import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        // TODO Auto-generated method stub

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());
        int abc = 1;

        while (testcase-- > 0) {

            String[] input_sen = new String[2];
            input_sen = br.readLine().split(" ");
            Vector ve = new Vector();
            char[] sen = input_sen[1].toCharArray();

            for (int i = 0; i < sen.length; i++) {

                ve.add(sen[i]);

            }


            int remove_int = Integer.parseInt(input_sen[0]);


            ve.remove(remove_int - 1);

            String result_sen = "";

            for (int a = 0; a < ve.size(); a++) {

                result_sen += ve.get(a);
            }


            System.out.println(abc + " " + result_sen);

            abc++;


        }

    }

}
