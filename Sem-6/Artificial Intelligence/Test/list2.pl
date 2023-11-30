% find out the last member of a list.
lastElement(X, [X]).
lastElement(X, [_|L]):- lastElement(X, L).

conList([],L,L).
conList([X|L1], L2, [X|L3]):- conList(L1, L2, L3).

% find the reverse of a list
reverseList([], []).
reverseList([X], [X]).
reverseList([X|L], R):- reverseList(L, T), conList(T, [X], R).

% check palindrome of a list
palindrome(X) :- reverseList(X,X).

% insert in X in all possible positions
insert(X,[],[X]).
insert(X,[Y|T],[X,Y|T1]) :- insert(X,T,T1).

% check palindrome using concatenate
palindrome2([]).
palindrome2([_]).
palindrome2([X|T]):- conList(L, [X], T), palindrome2(L).

% check whether a list is of odd length
even([]).
even([_|T]) :- odd(T).
odd([_]).
odd([_|T]) :- even(T).

even2([]).
even2([_,_|T]):- even2(T).

% find out the length of a list
lengthList([],0).
lengthList([_|T],N):- lengthList(T,N1), N is N1+1. 

% find all prefixes and suffixes of a list
prefixes([], _).
prefixes([H|T], [H|L]):- prefixes(T, L).
suffix(L, L).
suffix(L1,[_|L2]):- suffix(L1, L2).

% find all permutations of a list
permute([], []).
permute(L, [X|T]) :-
    delete(X, L, L1),
    permute(L1, T).
delete(X, [X|T], T).
delete(X, [H|T], [H|T1]) :-
    delete(X, T, T1).