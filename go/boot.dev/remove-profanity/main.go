package main

import (
	"fmt"
)

func contains(s string, subs string) (bool, int) {
	r := []rune(s)
	sr := []rune(subs)
	check := []rune{}
	found := false

	for i, val := range r {
		if val == sr[0] {
			check = []rune{sr[0]}
			continue
		}
		check = append(check, val)
		if string(check) == string(sr) {
			found = true
			return found, (i - len(check)) + 1
		}
	}

	return found, 0
}

// func removeProfanity(message *string) {
//
// }

func test() {
	word := "llama"
	sentence := "i use llama 3"

	ok, i := contains(sentence, word)
	fmt.Println(ok, i)
}

func main() {
	test()
	// wordsToFind := []string{"fubb", "shiz", "witch"}
	// sentence := "Oh man I've seen some crazy ass shiz in my time...fizz, fubb, xd, witch, shiz, llama"
	//
	// for _, word := range wordsToFind {
	// 	doesIt, where := contains(sentence, word)
	//
	// 	r := []rune(sentence)
	//
	// 	if doesIt {
	// 		for i := where; i <= where+len(word)-1; i++ {
	// 			r[i] = '*'
	// 		}
	// 	}
	//
	// 	sentence = string(r)
	// }
	//
	// fmt.Println(string(sentence))
}
