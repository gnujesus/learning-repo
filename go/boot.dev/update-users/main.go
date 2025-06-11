package main

import "fmt"

type Membership struct {
	Type             string
	MessageCharLimit int
}

type User struct {
	Name string
	Membership
}

func newUser(name string, membershipType string) User {
	charLimit := 0

	if membershipType == "premium" {
		charLimit = 1000
	} else {
		charLimit = 100
	}

	user := User{
		Name: name,
		Membership: Membership{
			Type:             membershipType,
			MessageCharLimit: charLimit,
		},
	}

	return user
}

func (u User) sendMessage(message string, messageLength int) (string, bool) {
	if messageLength <= u.Membership.MessageCharLimit {
		return message, true
	} else {
		return "", false
	}
}

func main() {
	jesus := newUser("Jesus", "")

	fmt.Println(jesus)
}
