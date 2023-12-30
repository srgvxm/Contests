package main

import (
	"fmt"
)

type Stack interface {
	empty() bool
	push(r rune)
	top() rune
	pop() rune
}

type SimpleStack struct {
    data []rune
}

func NewSimpleStack() *SimpleStack {
    return &SimpleStack{}
}

func (s *SimpleStack) empty() bool {
    return len(s.data) == 0
}

func (s *SimpleStack) push(r rune) {
    s.data = append(s.data, r)
}

func (s *SimpleStack) top() rune {
    if s.empty() {
        return 0
    }
    return s.data[len(s.data)-1]
}

func (s *SimpleStack) pop() rune {
    if s.empty() {
        return 0
    }
    popped := s.data[len(s.data)-1]
    s.data = s.data[:len(s.data)-1]
    return popped
}

func bracketValidator(stack Stack, str string) bool {
	mapping := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}

	for _, char := range str {
		if char == '(' || char == '[' || char == '{' {
			stack.push(char)
		} else if char == ')' || char == ']' || char == '}' {
			if stack.empty() || stack.top() != mapping[char] {
				return false
			}
			stack.pop()
		}
	}

	return stack.empty()
}

func main() {
	var input string
	fmt.Scan(&input)
	fmt.Println(bracketValidator(NewSimpleStack(), input))
}
