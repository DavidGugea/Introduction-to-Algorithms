import math

class BinaryHeap:
    def __init__(self) -> None:
        self.heap: list[int] = []

    def parent(self, i: int) -> int:
        return math.floor(i / 2)

    def left(self, i: int) -> int:
        return 2 * i

    def right(self, i: int) -> int:
        return 2 * i + 1

    def swap(self, i: int, j: int) -> None:
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def max_heapify(self, i) -> None:
        l: int = self.left(i)
        r: int = self.right(i)

        if l < len(self.heap) and self.heap[l] > self.heap[i]:
            largest = l
        else:
            largest = i

        if r < len(self.heap) and self.heap[r] > self.heap[largest]:
            largest = r

        if largest != i:
            self.swap(i, largest)
            self.max_heapify(largest)

    def build_max_heap(self, array: list[int]) -> None:
        self.heap = array
        for i in range(math.floor(len(self.heap) / 2), 1, -1):
            self.max_heapify(i)

    def heapsort(self, array: list[int]) -> None:
        self.build_max_heap(array)

        for i in range(len(self.heap), 2, -1):
            self.swap(1, i)
            self.max_heapify(1)
