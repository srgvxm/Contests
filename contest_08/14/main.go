package main

import (
	"fmt"
	"math/rand"
	"time"
)


type Board [3][3]string

func NewBoard() Board{
	return [3][3]string {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}}
}

func (b *Board) set(row, col int, marker string) (ok bool){
	if b[row][col] != " " {
		return false
	}
	b[row][col] = marker
	return true
}

func (b *Board) isGameOver() (ok bool, winner string){
	for row := 0; row < 3; row++ {
		if b[row][0] != " " && b[row][0] == b[row][1] && b[row][0] == b[row][2] {
			return true, b[row][0]
		}
	}

	for col := 0; col < 3; col++ {
		if b[0][col] != " " && b[0][col] == b[1][col] && b[0][col] == b[2][col] {
			return true, b[0][col]
		}
	}

	if b[0][0] != " " && b[0][0] == b[1][1] && b[0][0] == b[2][2] {
		return true, b[0][0]
	}
	if b[0][2] != " " && b[0][2] == b[1][1] && b[0][2] == b[2][0] {
		return true, b[0][2]
	}

	isDraw := true
	for row := 0; row < 3; row++ {
		for col := 0; col < 3; col++ {
			if b[row][col] == " " {
				isDraw = false
				break
			}
		}
	}

	return isDraw, "-"
}


type Bot interface{
	startGame(marker string)
	getMarker() string
	step(board Board) (row, col int, marker string)
	endGame(winner string)
}


type RandomBot struct{
	marker string
}

func NewRandomBot() *RandomBot{
	return &RandomBot{"?"}
}

func (b *RandomBot) startGame(marker string){
	b.marker = marker
}

func (b *RandomBot) getMarker() string{
	return b.marker
}

func (b *RandomBot) step(board Board) (row, col int, marker string){
	for {
		row, col, marker = rand.Intn(3), rand.Intn(3), b.marker
		if board[row][col] == " " {
			return
		}
	}
}

func (b *RandomBot) endGame(winner string){
	// Бот не обучается
}

type UserBot struct {
    marker string
}

func NewUserBot() *UserBot {
    return &UserBot{"?"}
}

func (b *UserBot) startGame(marker string) {
    b.marker = marker
}

func (b *UserBot) getMarker() string {
    return b.marker
}

func (b *UserBot) step(board Board) (row, col int, marker string) {
    for row := 0; row < 3; row++ {
        for col := 0; col < 3; col++ {
            if board[row][col] ==" " {
                board[row][col] = b.marker
                if ok, _ := board.isGameOver(); ok {
                    return row, col, b.marker
                }
                board[row][col] = " " 
            }
        }
    }

    opponentMarker := "O"
    if b.marker == "O" {
        opponentMarker = "X"
    }
    for row := 0; row < 3; row++ {
        for col := 0; col < 3; col++ {
            if board[row][col] == " " {
                board[row][col] = opponentMarker
                if ok, _ := board.isGameOver(); ok {
                    return row, col, b.marker
                }
                board[row][col] = " " 
            }
        }
    }

    for {
        row, col = rand.Intn(3), rand.Intn(3)
        if board[row][col] == " " {
            return row, col, b.marker
        }
    }
}

func (b *UserBot) endGame(winner string) {
    // Бот не обучается
}

func main() {
	rand.Seed(time.Now().UnixNano())
	trainGames, battleGames := 10000, 1000
	totalGames := trainGames + battleGames
	
	userBot := NewUserBot()
	randomBot := NewRandomBot()
	
	var winsCount int
	for i:=0; i<totalGames; i++{
		isRandomBotTurn := (rand.Int() % 2 == 0)
		if isRandomBotTurn {
			randomBot.startGame("X")
			userBot.startGame("O")
		}else{
			randomBot.startGame("O")
			userBot.startGame("X")
		}
	
		board := NewBoard()
		for {
			if ok, winner := board.isGameOver(); ok {
				userBot.endGame(winner)
				randomBot.endGame(winner)
				if i >= trainGames {
					if winner != "-" && winner != randomBot.getMarker() {
						winsCount++
					}
				}

				break
			}
			
			if isRandomBotTurn {
				if !board.set(randomBot.step(board)) {
					panic("Сell is not empty")
				}
			}else{
				if !board.set(userBot.step(board)) {
					panic("Сell is not empty")
				}
			}
			isRandomBotTurn = !isRandomBotTurn
		}
	}
	
	if (winsCount >= int(0.8 * float64(battleGames))){
		fmt.Println("YES")
	}else{
		fmt.Println("NO")
	}
}
