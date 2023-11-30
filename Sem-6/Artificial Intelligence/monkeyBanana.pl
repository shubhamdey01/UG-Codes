% Monkey-Banana Problem

% grasp the banana
move(state(middle,onBox,middle,hasNot),
	grasp,
	state(middle,onBox,middle,has)).

% climb the box
move(state(H,onFloor,H,P),
	climb,
	state(H,onBox,H,P)).

% push the box
move(state(H1,onFloor,H1,P),
	push(H1,H2),
	state(H2,onFloor,H2,P)).

% walk on the floor
move(state(H1,onFloor,H,P),
	walk(H1,H2),
	state(H2,onFloor,H,P)).

% Final State
canGet(state(_,_,_,has)).

% move S1 to S2 by some move
canGet(S1) :- move(S1,_,S2),
	canGet(S2).