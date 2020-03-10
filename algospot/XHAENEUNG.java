import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

public class Main {

	static int final_answer(String write_answer, String check_answer) {

		char[] wr_an = write_answer.toCharArray();
		char[] ch_an = check_answer.toCharArray();

		int flag = 0;
		Arrays.sort(wr_an);
		Arrays.sort(ch_an);

		if (wr_an.length != ch_an.length) {

			flag = 0;

		}

		else {

			for (int i = 0; i < wr_an.length; i++) {

				if (wr_an[i] != ch_an[i]) {

					flag = 0;
					break;

				}

				else {

					flag = 1;
				}
			}
		}

		return flag;

	}

	static int change_language(String number) {

		int change_number = 0;

		switch (number) {

		case "zero":
			change_number = 0;
			break;
		case "one":
			change_number = 1;
			break;
		case "two":
			change_number = 2;
			break;
		case "three":
			change_number = 3;
			break;
		case "four":
			change_number = 4;
			break;
		case "five":
			change_number = 5;
			break;
		case "six":
			change_number = 6;
			break;
		case "seven":
			change_number = 7;
			break;
		case "eight":
			change_number = 8;
			break;
		case "nine":
			change_number = 9;
			break;
		default:
			change_number = 10;
			break;

		}

		return change_number;
	}

	static String change_number(int int_answer) {

		String change_string;

		switch (int_answer) {

		case 0:
			change_string = "zero";
			break;
		case 1:
			change_string = "one";
			break;
		case 2:
			change_string = "two";
			break;
		case 3:
			change_string = "three";
			break;
		case 4:
			change_string = "four";
			break;
		case 5:
			change_string = "five";
			break;
		case 6:
			change_string = "six";
			break;
		case 7:
			change_string = "seven";
			break;
		case 8:
			change_string = "eight";
			break;
		case 9:
			change_string = "nine";
			break;
		default:
			change_string = "ten";
			break;

		}

		return change_string;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		int divide = 0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int testcase = Integer.parseInt(br.readLine());

		while (testcase-- > 0) {

			String[] sentence = new String[5];
			sentence = br.readLine().split(" ");
			// long start = System.currentTimeMillis();

			int first_number = change_language(sentence[0]);
			int second_number = change_language(sentence[2]);
			int answer = 0;
			int answer_flag = 0;
			String str_answer;

			switch (sentence[1]) {

			case "+":
				answer = first_number + second_number;
				break;
			case "-":
				answer = first_number - second_number;
				break;
			case "*":
				answer = first_number * second_number;
				break;
			default:
				divide = 1;
				break;

			}

			if (answer < 0 || answer > 10) {

				answer_flag = 0;

			}

			else {

				if (divide == 1) {
					if (second_number == 0)
						answer_flag = 0;
					else {
						answer = first_number / second_number;
					}
				}


					str_answer = change_number(answer);
					answer_flag = final_answer(sentence[4], str_answer);


			}

			if (answer_flag == 1)
				System.out.println("Yes");
			else
				System.out.println("No");

		}

	}

}
