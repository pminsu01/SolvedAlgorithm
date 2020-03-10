import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class find{

	String locate(String locate1, String locate2, String locate3){

		String final_locate="";

		if(locate1.equals(locate2)){

			final_locate= locate3;
		}

		else {

			if(locate1.equals(locate3)){

				final_locate = locate2;
			}

			else {

				final_locate= locate1;
			}
		}

		return final_locate;
	}
}

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCase = Integer.parseInt(br.readLine());
		find f = new find();

		while(testCase--> 0){

			String x_result = "";
			String y_result = "";
			String[] a1_locate = new String[2];
			String[] a2_locate = new String[2];
			String[] a3_locate = new String[2];

			String a1 = br.readLine();
			String a2 = br.readLine();
			String a3=  br.readLine();

			a1_locate= a1.split(" ");
			a2_locate =a2.split(" ");
			a3_locate= a3.split(" ");

			x_result =f.locate(a1_locate[0], a2_locate[0],a3_locate[0]);
			y_result =f.locate(a1_locate[1], a2_locate[1],a3_locate[1]);



			 System.out.println(x_result +" "+y_result);

		}

	}

}
