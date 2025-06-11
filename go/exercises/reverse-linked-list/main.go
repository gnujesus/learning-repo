package main

import "fmt"

type Node struct {
	value int
	next  *Node
}

func printList(head *Node) {
	var temp *Node = head

	for true {
		fmt.Printf("%d, %p \n", temp.value, temp.next)

		if temp.next == nil {
			break
		}
		temp = temp.next
	}
}

func reverse(head *Node) *Node {
	var curr *Node
	var prev *Node

	for head != nil {
		curr = head
		head = head.next
		curr.next = prev
		prev = curr
	}

	return curr
}

func main() {
	var head *Node

	firstNode := Node{value: 1, next: nil}
	secondNode := Node{value: 2, next: nil}
	firstNode.next = &secondNode

	thirdNode := Node{value: 3, next: nil}
	secondNode.next = &thirdNode

	head = &firstNode

	head = reverse(head)
	printList(head)
}
