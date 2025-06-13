package main

func getNameCounts(names []string) map[rune]map[string]int {
	var nested map[rune]map[string]int

	for _, val := range names {
		firstLetter := []rune(val)[0]

		_, ok := nested[firstLetter]

		if !ok {
			nested[firstLetter] = 
		}
	}

	return nested
}

func yourMyObsession(arr []string) string {
	for i, _ := range arr {
		if []rune(arr[i])[0] != []rune(arr[i+1])[0] {

		}
	}

	return "If God is a woman, then God is a weapon"
}

func main()
