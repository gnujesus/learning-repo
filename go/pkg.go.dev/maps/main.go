package main

import "fmt"

type Node struct {
	Next  *Node
	Value interface{}
}

func main() {
	var first *Node

	visited := make(map[*Node]bool)

	first = &Node{Value: "1"}
	first.Next = &Node{Value: "2"}
	first.Next.Next = &Node{Value: "3"}
	first.Next.Next.Next = first

	// 1. if first == nil, doesn't go into the loop, so first must exist.
	// 2. if first.Next == nil, there's no point in this example
	for n := first; n != nil; n = n.Next {

		// 3. if there isn't any cicle, this is never true, thus making the example pointless
		if visited[n] {
			fmt.Println("cycle detected")
			break
		}

		// add node and true to detect cycle
		visited[n] = true
		fmt.Println(n.Value)
	}
}
