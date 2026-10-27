import java.util.Scanner;

public class TicTacToe {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char board[][] = new char[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        char player = 'X';
        int moves = 0;

        System.out.println("Tic Tac Toe - 2 player game");
        System.out.println("Enter row and column numbers from 1 to 3");
        printBoard(board);

        while (true) {
            System.out.print("Player " + player + " enter row and col: ");
            int r = sc.nextInt();
            int c = sc.nextInt();

            if (r < 1 || r > 3 || c < 1 || c > 3) {
                System.out.println("Invalid position, try again");
                continue;
            }
            if (board[r - 1][c - 1] != ' ') {
                System.out.println("Cell already taken, try again");
                continue;
            }

            board[r - 1][c - 1] = player;
            moves++;
            printBoard(board);

            if (checkWin(board, player)) {
                System.out.println("Player " + player + " wins!");
                break;
            }
            if (moves == 9) {
                System.out.println("Match is a draw");
                break;
            }

            if (player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }
        }
    }

    static void printBoard(char b[][]) {
        System.out.println();
        for (int i = 0; i < 3; i++) {
            System.out.println(" " + b[i][0] + " | " + b[i][1] + " | " + b[i][2]);
            if (i < 2) {
                System.out.println("---+---+---");
            }
        }
        System.out.println();
    }

    // checks all 3 rows, 3 columns and both diagonals
    static boolean checkWin(char b[][], char p) {
        for (int i = 0; i < 3; i++) {
            if (b[i][0] == p && b[i][1] == p && b[i][2] == p) {
                return true;
            }
            if (b[0][i] == p && b[1][i] == p && b[2][i] == p) {
                return true;
            }
        }
        if (b[0][0] == p && b[1][1] == p && b[2][2] == p) {
            return true;
        }
        if (b[0][2] == p && b[1][1] == p && b[2][0] == p) {
            return true;
        }
        return false;
    }
}
