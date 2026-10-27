// simple quiz program

import java.util.Scanner;

public class QuizApplication {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        String q[] = new String[5];
        String opt[][] = new String[5][4];
        int ans[] = new int[5];

        q[0] = "Who developed the Java language?";
        opt[0][0] = "Dennis Ritchie";
        opt[0][1] = "James Gosling";
        opt[0][2] = "Bjarne Stroustrup";
        opt[0][3] = "Ken Thompson";
        ans[0] = 2;

        q[1] = "Which keyword is used to inherit a class in Java?";
        opt[1][0] = "this";
        opt[1][1] = "super";
        opt[1][2] = "extends";
        opt[1][3] = "implements";
        ans[1] = 3;

        q[2] = "What is the size of int in Java?";
        opt[2][0] = "2 bytes";
        opt[2][1] = "4 bytes";
        opt[2][2] = "8 bytes";
        opt[2][3] = "depends on OS";
        ans[2] = 2;

        q[3] = "Which of these is NOT a feature of Java?";
        opt[3][0] = "Object oriented";
        opt[3][1] = "Platform independent";
        opt[3][2] = "Use of pointers";
        opt[3][3] = "Robust";
        ans[3] = 3;

        q[4] = "Which method is the entry point of a Java program?";
        opt[4][0] = "start()";
        opt[4][1] = "run()";
        opt[4][2] = "init()";
        opt[4][3] = "main()";
        ans[4] = 4;

        int score = 0;

        System.out.println("Welcome to the Java Quiz");
        System.out.println("Type the option number (1-4) as your answer");
        System.out.println();

        for (int i = 0; i < 5; i++) {
            System.out.println("Q" + (i + 1) + ". " + q[i]);
            for (int j = 0; j < 4; j++) {
                System.out.println("  " + (j + 1) + ") " + opt[i][j]);
            }
            System.out.print("Your answer: ");
            int a = s.nextInt();

            if (a == ans[i]) {
                System.out.println("Correct!");
                score++;
            } else {
                System.out.println("Wrong! correct answer is " + ans[i] + ") " + opt[i][ans[i] - 1]);
            }
            System.out.println();
        }

        System.out.println("Quiz over");
        System.out.println("Your score is " + score + " out of 5");

        if (score == 5) {
            System.out.println("Excellent!");
        } else if (score >= 3) {
            System.out.println("Good attempt");
        } else {
            System.out.println("Better luck next time");
        }
    }
}
