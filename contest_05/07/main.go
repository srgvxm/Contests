package main

import "fmt"

type Water struct {
	temperature int
   }
   
   func NewWater(initialTemperature int) *Water {
	return &Water{
	 temperature: initialTemperature,
	}
   }
   
   func (w *Water) GetTemperature() int {
	return w.temperature
   }
   
   func (w *Water) IncreaseTemperature(degrees int) {
	w.temperature += degrees
   }
   
   type Teapot struct {
	water *Water
   }
   
   func NewTeapot(initialWater *Water) *Teapot {
	return &Teapot{
	 water: initialWater,
	}
   }
   
   func (t *Teapot) is_boiling() bool {
	return t.water.GetTemperature() >= 100
   }
   
   func (t *Teapot) heat_up(degrees int) {
	t.water.IncreaseTemperature(degrees)
   }
func main() {
	var temperature, count int
	fmt.Scan(&temperature, &count)

	heat := NewQueue()
	for i := 0; i < count; i++ {
		var t int
		fmt.Scan(&t)
		heat.Push(t)
	}

	water := NewWater(temperature)
	teapot := NewTeapot(water)

	for !teapot.is_boiling() {
		teapot.heat_up(heat.Pop())
	}

	for !heat.IsEmpty() {
		fmt.Print(heat.Pop(), " ")
	}
}
