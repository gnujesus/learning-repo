package main

import (
	"errors"
	"fmt"
)

func validateStatus(status string) error {
	if len(status) == 0 {
		return errors.New("status cannot be empty")
	} else if len([]rune(status)) > 140 {
		return errors.New("status exceeds 140 characters")
	}

	return nil
}

func main() {
	err := validateStatus("")

	newErr := fmt.Errorf("An error has ocurred:\n %w", err)

	fmt.Printf("%s", newErr)
}
