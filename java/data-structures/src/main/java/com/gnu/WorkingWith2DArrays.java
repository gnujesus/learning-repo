package com.gnu;

import java.util.Arrays;
import java.util.Scanner;

public class WorkingWith2DArrays {
    static char[][] board = new char[3][3];
    static Scanner input = new Scanner(System.in);

    static int column = 0;
    static int row = 0;

    // Will start with x, since the game changes to the next player on start
    static char currentPlayer = 'o';

    public static void main(String[] args) {
        initialize();
        start();
    }

    public static void getBoard(){

        // no space & faster
        // Arrays.stream(board).forEach(System.out::println);

        // space & slower
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                System.out.printf("%s ", board[i][j]);;
            }
            System.out.println();
        }
    }

    public static boolean winner(){
       //Vertical
        VerticalValidation:
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j ++){
                if(board[i][j] != currentPlayer){
                    continue VerticalValidation;
                }

                if(j == 2){
                    return true;
                }
            }

        }

        // Horizontal
        HorizontalValidation:
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j ++){
                if(board[j][i] != currentPlayer){
                    continue HorizontalValidation;
                }

                if (j == 2) {
                    return true;
                }
            }

        }

        // Diag left-right
        DiagLeftRightValidation:
        for(int i = 0; i < 3; i ++){
            if(board[i][i] != currentPlayer){
                break;
            }

            if (i == 2) {
                return true;
            }
        }


        // Diag right-left
        DiagRightLeftValidation:
        for(int i = 2; i > -1; i --){
            if(board[i][i] != currentPlayer){
                break;
            }

            if (i == 0) {
                return true;
            }
        }


        nextPlayer();
        return false;
    }

    public static void initialize(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = '-';
            }
        }
    }

    public static void nextPlayer(){
        if(currentPlayer == 'x'){
            currentPlayer = 'o';
        } else {
            currentPlayer = 'x';
        }
    }

    public static void start(){
        while(!winner()){
            getBoard();

            System.out.print("Column: ");
            column = Integer.parseInt(input.nextLine());

            if(column < 0 || column > 2){
                System.out.println("Sorry, not allowed...");
                continue;
            }

            System.out.print("Row: ");
            row= Integer.parseInt(input.nextLine());

            if(row < 0 || row > 2){
                System.out.println("Sorry, not allowed...");
                continue;
            }

            board[row][column] = currentPlayer;
        }

        getBoard();
        System.out.println("CONGRATS! WE HAVE A WINNER");
    }
}
