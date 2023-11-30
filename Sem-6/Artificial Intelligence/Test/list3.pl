listLength([], 0).
listLength([_|X], L) :- listLength(X, N), L is N+1.

% check if a list is doubletone or not
notDoubleTonned(L) :- listLength(L, N), N\=2.

nDt([]).
nDt([_]).
nDt([_|[_|[_|Rest]]]).

% whether two lists are same length or not
length2List(L1, L2) :- listLength(L1, N1), listLength(L2, N2), N1=:=N2.

equalLength([],[]).
equalLength([X|R1],[Y|R2]) :- equalLength(R1,R2).


isNatural(0).
isNatural(s(X)) :- isNatural(X).

even(0).
even(s(s(X))) :- even(X).
odd(s(0)).
odd(s(s(X))):- odd(X).

multipleOF3(0).
multipleOF3(s(s(s(X)))) :- multipleOF3(X).

isLessThan(0,Y) :- isNatural(Y).
isLessThan(s(X),s(Y)) :- isLessThan(X,Y).