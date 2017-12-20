package rps;

import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Rps {
	public static void main(String[] args) throws InterruptedException {
		Scanner reader = new Scanner(System.in); // Asks the user for number of searches
		System.out.println("Pick the total # of games, ie '3' means best of 3. Use odd numbers or it breaks."); 
		int games = reader.nextInt();
		int usrscore = 0;
		int compscore = 0;
		int minwin = (1 + games) / 2;
		while (games>0) {
		System.out.println("Pick either Rock, Paper, or Scissors"); 
		String usranswerraw = reader.nextLine();
		String usranswer = usranswerraw.toLowerCase(); // converts it into lower case for shorter code.
		if (usranswer.equals("rock") || usranswer.equals("paper") || usranswer.equals("scissors")) {
		Random r = new Random();
		int rand = r.nextInt((3 - 1) + 1) + 1; // generates random number
		String compans = "default";
		switch(rand) { // assigns the integer to a string
		case 1:
			compans = "rock";
			break;
		case 2:
			compans = "paper";
			break; 
		case 3:
			compans = "scissors";
			break;
		}
		System.out.println("Three!");
		TimeUnit.SECONDS.sleep(1);
		System.out.println("Two!");
		TimeUnit.SECONDS.sleep(1);
		System.out.println("One!");
		TimeUnit.SECONDS.sleep(1);
		
		if (compans.equals(usranswer)) {
			System.out.println("It's a draw!");
			System.out.println("Computer chose " + compans + ". You also chose " + usranswer + "."); 
		}
		else {
			games--;
		if (compans.equals("rock") && usranswer.equals("paper")) { System.out.println("You win!"); usrscore++;} // calculates who wins
		else if (compans.equals("paper") && usranswer.equals("rock")) { System.out.println("Computer wins!"); compscore++;}
		else if (compans.equals("rock") && usranswer.equals("scissors")) { System.out.println("Computer wins!"); compscore++;}
		else if (compans.equals("scissors") && usranswer.equals("rock")) { System.out.println("You win!"); usrscore++;}
		else if (compans.equals("scissors") && usranswer.equals("paper")) { System.out.println("Computer wins!"); compscore++;}
		else if (compans.equals("paper") && usranswer.equals("scissors")) { System.out.println("You win!"); usrscore++;}
		
		System.out.println("Computer chose " + compans + ". You chose " + usranswer + "."); 
		System.out.println("The current score is You: " + usrscore + " Computer: " + compscore);
		}
		if (compscore == minwin) {System.out.println("Computer wins the overall game!!!"); games=0;} else if (usrscore == minwin){System.out.println("You have won the overall game!!!"); games=0;}
		}
		}
		reader.close();
	}
}
