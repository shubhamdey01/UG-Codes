f(X,0) :- X < 3.
f(X,1) :- X >= 3, X < 6.
f(X,2) :- X >= 6.

% Green Cut - 
f1(X,0) :- X < 3, !.
f1(X,1) :- X >= 3, X < 6, !.
f1(X,2) :- X >= 6.

% Red Cut -
f2(X,0) :- X < 3, !.
f2(X,1) :- X < 6, !.
f2(X,2).

f3(X,0) :- X < 3.
f3(X,1) :- X < 6.
f3(X,2).

% maximum of two elements
max(X, Y, X) :- X >= Y.
max(X, Y, Y) :- X < Y.

% maximum of two elements using cut
max2(X, Y, X) :- X >= Y, !.
max2(X, Y, Y).

% check whether element X is a member of list L
member(X, [X|_]).
member(X, [Y|L]) :- member(X,L).

% check whether element X is a member of list L using cut
member2(X, [X|_]) :- !.
member2(X, [Y|L]) :- member2(X,L).

% add element X to list L without duplication
add(X, L, L) :- member2(X, L), !.
add(X, L, [X|L]).

% remove the first occurence of element X from the list Y giving a new list Z
efface(_, [], []).
efface(X,[X|L], L) :- !.
efface(X, [Y|L], [Y|L1]) :- efface(X,L,L1).

% maximum of list
maxList([X], X).
maxList([X|[Y|L]], M) :- maxList([Y|L], R), max2(R, X, M).

% sum of list
sumList([], 0).
sumList([X|L], Y) :- sumList(L, S), Y is X+S.