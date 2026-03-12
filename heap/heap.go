package main

import "errors"

type Heap struct {
	arr        []int
	size       int
	total_size int
}

func NewMaxHeap(n int) *Heap {
	Narr := make([]int, 0, n)
	maxHeap := Heap{
		arr:        Narr,
		size:       0,
		total_size: n,
	}
	return &maxHeap
}

func (h *Heap) Insert(n int) error {
	if h.size == h.total_size {
		return errors.New("heap Overflow")
	}
	
}

func main() {

}
