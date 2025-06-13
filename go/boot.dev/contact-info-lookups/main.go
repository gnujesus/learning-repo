package main

import (
	"errors"
	"fmt"
)

func getUserMap(names []string, phoneNumbers []int) (map[string]user, error) {
	if len(names) != len(phoneNumbers) {
		return make(map[string]user), errors.New("invalid sizes")
	}

	usersMap := make(map[string]user)

	for i, val := range names {
		usersMap[val] = user{name: val, phoneNumber: phoneNumbers[i]}
	}

	return usersMap, nil
}

type user struct {
	name        string
	phoneNumber int
}

func main() {
	res, err := getUserMap([]string{"Jesus", "Muhammed"}, []int{123, 321})

	if err != nil {
		fmt.Printf("%s", err)
	}

	fmt.Println(res)
}
