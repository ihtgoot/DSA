package main

import (
	"errors"
	"fmt"
)

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
	h.arr = append(h.arr, n)
	idx := h.size
	parent := (idx - 1) / 2
	for idx > 0 && h.arr[parent] < h.arr[idx] {
		h.arr[idx], h.arr[parent] = h.arr[parent], h.arr[idx]
		idx = parent
		parent = (idx - 1) / 2
	}
	h.size++
	return nil
}



func (h *Heap) show() {
	fmt.Println(h.arr)
}

func main() {
	var n int
	fmt.Scan(&n)
	heap := NewMaxHeap(n)
	for i := 0; i < n; i++ {
		var k int
		fmt.Scan(&k)
		heap.Insert(k)
	}
	heap.show()

}
