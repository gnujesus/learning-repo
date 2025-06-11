package main

import (
	"fmt"
)

func reverseText(s string) string {
	var reversed []rune

	for _, r := range s {
		// create new slice with current letter -> append old slice to new slice -> assign to old slice
		reversed = append([]rune{r}, reversed...)
	}

	return string(reversed)
}

func charStats(s string) map[string]int {

	non_ascii_count := 0
	ascii_count := 0

	// Problem: you're iterating over BYTES, not runes
	// This will give wrong counts for multi-byte Unicode characters
	/*
		for i := range len(s) {
			if s[i] > 128 {
				non_ascii_count++
			}
		}
	*/

	for _, r := range s {
		if r <= 127 {
			ascii_count++
		} else {
			non_ascii_count++
		}
	}

	// ascii_count = non_ascii_count - len([]rune(s))

	/*
		if ascii_count < 0 {
			ascii_count = -ascii_count
		}
	*/

	stats := map[string]int{
		"total_runes":    len([]rune(s)),
		"total_bytes":    len(s),
		"ascii_count":    ascii_count,
		"no_ascii_count": non_ascii_count,
	}

	return stats
}

func isPalindrome(s string) bool {
	reversed := reverseText(s)
	return reversed == s
}

func main() {
	fmt.Println(reverseText("hello 世界"))
	fmt.Println(charStats("hello 世界"))
	fmt.Println(isPalindrome("xdx"))
}
