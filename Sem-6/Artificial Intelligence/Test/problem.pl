% Monkey-Banana Problem

move(state(middle,onBox,middle,hasNot), grasp, state(middle,onBox,middle,has)).
move(state(H,onFloor,H,P), climb, state(H,onBox,H,P)).
move(state(H1,onFloor,H1,P), push(H1,H2), state(H2,onFloor,H2,P)).
move(state(H1,onFloor,H,P), walk(H1,H2), state(H2,onFloor,H,P)).

canGet(state(_,_,_,has)).
canGet(S1) :- move(S1,_,S2), canGet(S2).


% 8-Queens Problem

solution([]).

solution([X/Y|Others]):- 
	solution(Others),
	member(Y,[1,2,3,4,5,6,7,8]),
	noattack(X/Y, Others).

noattack(_,[]).

noattack(X/Y,[X1/Y1|Others]):-
	Y =\= Y1,
	(Y1-Y) =\= (X1-X),
	(Y1-Y) =\= (X-X1),
	noattack(X/Y, Others).

% member(X,[X|_]) :- !.

% member(X,[_|Rest]) :- member(X, Rest).

template([1/Y1, 2/Y2, 3/Y3, 4/Y4, 5/Y5, 6/Y6, 7/Y7, 8/Y8]).