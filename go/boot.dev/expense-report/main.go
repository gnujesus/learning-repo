package main

// Both are valid approches

/*
func getExpenseReport(e expense) (string, float64) {
	if emailValue, ok := e.(email); ok {
		return emailValue.toAddress, emailValue.cost()
	} else if s, ok := e.(sms); ok {
		return s.toPhoneNumber, s.cost()
	} else {
		return "", 0.0
	}
}
*/

func getExpenseReport(e expense) (string, float64) {
	switch t := e.(type) {
	case email:
		return t.toAddress, t.cost()
	case sms:
		return t.toPhoneNumber, t.cost()
	default:
		return "", 0.0
	}
}

// don't touch below this line

type expense interface {
	cost() float64
}

type email struct {
	isSubscribed bool
	body         string
	toAddress    string
}

type sms struct {
	isSubscribed  bool
	body          string
	toPhoneNumber string
}

type invalid struct{}

func (e email) cost() float64 {
	if !e.isSubscribed {
		return float64(len(e.body)) * .05
	}
	return float64(len(e.body)) * .01
}

func (s sms) cost() float64 {
	if !s.isSubscribed {
		return float64(len(s.body)) * .1
	}
	return float64(len(s.body)) * .03
}

func (i invalid) cost() float64 {
	return 0.0
}
