import java.util.Scanner;

class Change {


	String change_pass(String password) {

		char[] jjaksu= new char[100];
		char[] holsu = new char[100];
		String jak="";
		String hol="";
		String result;

		//String password="";



		char[] main_sentence = password.toCharArray();

		for(int i =0; i< main_sentence.length; i++) {

			int a=0;
			int b=0;
			if(i %2 ==0) {

				jak += Character.toString(main_sentence[i]);
			}

			else {

				hol += Character.toString(main_sentence[i]);
				b++;
			}


		}


		result = jak+hol;
		return result;


	}

}

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Change change =new Change();
		Scanner scanner = new Scanner(System.in);

		int term = scanner.nextInt();


		while(term !=0) {

			String input_password = scanner.next();
			String output_password = change.change_pass(input_password);

			System.out.println(output_password);


			term--;


		}





	}

}
