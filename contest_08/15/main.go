package main

import (
    "fmt"
)

import "strconv"
import "strings"

type BinaryTreeNode struct {
    value  int
    left   *BinaryTreeNode
    right  *BinaryTreeNode
    parent *BinaryTreeNode
}

func NewBinaryTreeNode(value int) *BinaryTreeNode {
    return &BinaryTreeNode{
        value: value,
    }
}

func (t *BinaryTreeNode) insertNode(value int) {
    if value < t.value {
        if t.left != nil {
            t.left.insertNode(value)
        } else {
            t.left = NewBinaryTreeNode(value)
            t.left.parent = t
        }
    } else if value > t.value {
        if t.right != nil {
            t.right.insertNode(value)
        } else {
            t.right = NewBinaryTreeNode(value)
            t.right.parent = t
        }
    }
}

func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
    if value < t.value {
        if t.left != nil {
            t.left = t.left.removeNode(value)
        }
    } else if value > t.value {
        if t.right != nil {
            t.right = t.right.removeNode(value)
        }
    } else {
        if t.left == nil && t.right == nil {
            if t.parent != nil {
                if t.parent.left == t {
                    t.parent.left = nil
                } else {
                    t.parent.right = nil
                }
            }
            return nil
        } else if t.left == nil {
            if t.parent != nil {
                if t.parent.left == t {
                    t.parent.left = t.right
                } else {
                    t.parent.right = t.right
                }
            }
            t.right.parent = t.parent
            return t.right
        } else if t.right == nil {
            if t.parent != nil {
                if t.parent.left == t {
                    t.parent.left = t.left
                } else {
                    t.parent.right = t.left
                }
            }
            t.left.parent = t.parent
            return t.left
        } else {
            maxLeft := t.left
            for maxLeft.right != nil {
                maxLeft = maxLeft.right
            }
            t.value = maxLeft.value
            t.left = t.left.removeNode(maxLeft.value)
        }
    }
    return t
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
    if t.value == value {
        return t
    } else if value < t.value {
        if t.left != nil {
            return t.left.findNode(value)
        }
    } else {
        if t.right != nil {
            return t.right.findNode(value)
        }
    }
    return nil
}

func (t *BinaryTreeNode) String() string {
    var result strings.Builder
    queue := []*BinaryTreeNode{t}

    for len(queue) > 0 {
        node := queue[0]
        queue = queue[1:]

        result.WriteString(strconv.Itoa(node.value))
        result.WriteRune(' ')

        if node.left != nil {
            queue = append(queue, node.left)
        }
        if node.right != nil {
            queue = append(queue, node.right)
        }
    }

    return strings.TrimSpace(result.String())
}

func main() {
    var count int
    fmt.Scan(&count)
    
    var root *BinaryTreeNode
    for count > 0 {
        var command string
        var value int
        fmt.Scan(&command, &value)
        
        if command == "insert" {
            if root == nil {
                root = NewBinaryTreeNode(value)
            }
            root.insertNode(value)
        }else if command == "remove" {
            root = root.removeNode(value)
        }else if command == "find" {
            fmt.Println(root.findNode(value))
        }
        
        count--
    }
}