package main

import (
 "encoding/json"
 "fmt"
 "io/ioutil"
 "os"
)

type Task struct {
 UserID    int  `json:"user_id"`
 Completed bool `json:"completed"`
}

type Data []struct {
 Tasks []Task `json:"tasks"`
}

func main() {
 var ID, sums int
 fmt.Scan(&ID)
 file, _ := os.Open("data.json")
 defer file.Close()
 byteValue, _ := ioutil.ReadAll(file)
 var data Data
 json.Unmarshal(byteValue, &data)
 for _, i := range data {
  for _, j := range i.Tasks {
   if j.UserID == ID && j.Completed {
    sums++
   }
  }
 }
 fmt.Println(sums)
}