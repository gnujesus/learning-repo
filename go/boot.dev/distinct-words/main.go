package main

import (
	"fmt"
	"strings"
)

func countDistinctWords(messages []string) int {
	if len(messages) == 0 {
		return 0
	}

	messagesString := strings.Join(messages, " ")
	messagesStringLowered := strings.ToLower(messagesString)
	wordsSlice := strings.Split(messagesStringLowered, " ")

	wordCount := map[string]int{}

	for _, val := range wordsSlice {
		val = strings.TrimSpace(val)
		if val != "" {
			wordCount[val] = 1
		}
	}

	result := 0

	for _, val := range wordCount {
		result += val
	}

	return result
}

func main() {
	fmt.Println(countDistinctWords([]string{"         "}))
}
