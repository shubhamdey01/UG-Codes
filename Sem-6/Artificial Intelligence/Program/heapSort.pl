heap_sort(List, SortedList):-
  list_heap(List, Heap),
  heap_list(Heap, SortedList).

list_heap(List, Heap):-list_heap_1(List, void, Heap).

list_heap_1([X|Xs], Heap0, Heap):-
  insert_heap(X, Heap0, Heap1),
  list_heap_1(Xs, Heap1, Heap).
list_heap_1([], Heap, Heap).

heap_list(void, []):-!.
heap_list(Heap, [X|Xs]):-
  remove_heap(X, Heap, Heap1),
  heap_list(Heap1, Xs).

insert_heap(Value, heap(Top, Left, Right), heap(Top, Right, Left1)):-
  Value < Top, !,
  insert_heap(Value, Left, Left1).
insert_heap(Value, heap(Top, Left, Right), heap(Value, Right, Left1)):-
  insert_heap(Top, Left, Left1).
insert_heap(Value, void, heap(Value, void, void)).

remove_heap(Top, heap(Top, void, Right), Right):-!.
remove_heap(Top, heap(Top, Left, Right), NewHeap):-
  remove_heap_1(Value1, Right, Right1),
  heap(heap(Value1, Right1, Left), NewHeap).

remove_heap_1(Top, heap(Top, void, Right), Right):-!.
remove_heap_1(Value, heap(Top, Left, Right), heap(Top, Left1, Left)):-
  remove_heap_1(Value, Right, Left1).

heap(heap(Top, heap(LeftValue, LeftLeft, LeftRight),
               heap(RightValue, RightLeft, RightRight)),
     heap(LeftValue, Left, heap(RightValue, RightLeft, RightRight))):-
  RightValue < LeftValue, Top < LeftValue, !,
  heap(heap(Top, LeftLeft, LeftRight), Left).
heap(heap(Top, Left, heap(RightValue, RightLeft, RightRight)),
     heap(RightValue, Left, Right)):-
  Top < RightValue, !,
  heap(heap(Top, RightLeft, RightRight), Right).
heap(Heap, Heap).