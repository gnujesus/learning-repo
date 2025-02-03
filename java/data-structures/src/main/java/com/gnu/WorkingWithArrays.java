package com.gnu;

import java.util.Arrays;

public class WorkingWithArrays {
    public static void main(String[] args) {

        int[] integerArray = new int[5];

        integerArray[0] = 2;
        integerArray[1] = 3;

        System.out.println(Arrays.toString(integerArray));

        String[] fruits = {"Pineapple", "Watermelon"};

        Arrays.stream(fruits).forEach(System.out::println);
        // shorthand for x -> System.out.prinln(x)
    }
}
