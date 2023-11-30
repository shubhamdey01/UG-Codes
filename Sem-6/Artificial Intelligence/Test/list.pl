% Find whether X is a member of the list or not

member(X,[X|_]).
member(X,[_|Rest]):-
	member(X,Rest).

% Concatenate L1 & L2 to form L3

conList([],L,L).
conList([X|L1], L2, [X|L3]):-
	conList(L1, L2, L3).

member1(X,L):-
	conList(L1,[X|L2],L).	% L1 X L2

% adding an item X to the beginning of a list L

add(X,L,[X|L]).

add1(X,L1,L):-
	conList([X],L1,L).

% delete the first occurence of the element X of a list L

% delete(X, [X], []).
delete(X,[X|L1], L1).
delete(X, [Y|L2], [Y|L1]) :- delete(X,L2,L1).

% delete all occurence of the element X of a list L

deleteAll(X, [], []).
deleteAll(X, [Y|L1], [Y|L2]):- X\=Y, deleteAll(X,L1,L2).
deleteAll(X,[X|L1],L2):- deleteAll(X,L1,L2).

% deleteAll(X,[],[]).
% deleteAll(X,[X|L],L1):- deleteAll(X,L,L1).
% deleteAll(X,[Y|L],L1):- deleteAll(X,L,L2), conList([Y],L2,L1).

% find out the last member of a list.
lastElement([X], X).
lastElement([_|L],X):- lastElement(L,X).