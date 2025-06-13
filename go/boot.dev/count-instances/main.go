package main

import "fmt"

func getCounts(messagedUsers []string, validUsers map[string]int) {
	for _, user := range messagedUsers {
		if _, ok := validUsers[user]; ok {
			validUsers[user] += 1
		}
	}
}

func main() {
	valid := map[string]int{"cersei": 0, "jaime": 0, "tyrion": 0}
	getCounts([]string{"cersei", "tyrion", "jaime", "tyrion", "tyrion"}, valid)

	fmt.Println(valid)
}
