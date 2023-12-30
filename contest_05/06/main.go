type Cat struct {
    alive bool
}

func NewCat(state bool) Cat {
    return Cat{
    alive: state,
    }
}

func (c Cat) is_alive() bool {
    return c.alive
}

type Box struct{}

func (b Box) open() Cat {
    state := rand.Intn(2) == 0
    return NewCat(state)
}