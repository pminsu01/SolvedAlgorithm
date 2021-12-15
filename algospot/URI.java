import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


class change_url {


    String change_string(String url) {

        String change_url = "";
        char[] main_sentence = url.toCharArray();

        for (int i = 0; i < main_sentence.length; i++) {

            if (main_sentence[i] == '%') {

                String aci_16 = Character.toString(main_sentence[i + 1]) + Character.toString(main_sentence[i + 2]);
                int inte_aci_16 = Integer.parseInt(aci_16, 16);

                change_url += (char) inte_aci_16;
                i = i + 2;


            } else {

                change_url += main_sentence[i];

            }


        }


        return change_url;
    }


}

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(br.readLine());


        while (testCase-- > 0) {

            String main_url = br.readLine();
            change_url method = new change_url();
            String result_url = method.change_string(main_url);

            System.out.println(result_url);


        }


    }

}
