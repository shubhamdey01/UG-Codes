parent(tom,bob).
parent(pam,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).

child(X,Y):-
	parent(Y,X).

grandparent(X,Y):-
	parent(X,Z), parent(Z,Y).

grandchild(X,Y):-
	parent(Z,X), parent(Y,Z).

male(tom).
female(pam).
male(bob).
female(liz).
male(pat).
female(ann).
male(jim).

father(X,Y):-
	parent(X,Y), male(X).

mother(X,Y):-
	parent(X,Y), female(X).

different(X,Y):-
	X\=Y.

brother(X,Y):-
	parent(Z,X), parent(Z,Y), male(X), different(X,Y).

sister(X,Y):-
	parent(Z,X), parent(Z,Y), female(X), different(X,Y).

predecessor(X,Y):-
	parent(X,Y); parent(X,Z), predecessor(Z,Y).

sibling(X,Y):-
	brother(X,Y); sister(X,Y).
	
aunt(X,Y):-
	parent(Z,Y), female(X), sibling(X,Z).
