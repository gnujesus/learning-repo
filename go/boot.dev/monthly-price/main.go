package main

func getMonthlyPrice(tier string) int {
	// ?
	tierMap := map[string]int{
		"basic": 10000,
		"premium": 15000,
		"enterprise": 50000,
	}
	
	return tierMap[tier] // returns 0 if not found
}


