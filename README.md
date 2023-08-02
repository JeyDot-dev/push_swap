Push swap rules :

1:	There is 2 stacks. 'a' & 'b'.

2:	'a' contains random integers (- +).

3:	Must sort from smallest to larger following stric rules.
	3a.	sa (swap a) :	swap 2 first items of the stack. Does nothing if only 1 or 0 items in th stack.
	3b.	sb (swap b) :	"	"	"	"	"	"	"	'	"	".
	3c.	ss (sa & sb).

	3d.	pa (push a)	:	Take first item from 'b' and puts on top of 'a'.
	3e.	pb (push b)	:	"	"	"	"	"	"'a'	"	"	"	"	'b'.

	3f.	ra (rotate a):	Shifts every element and puts first element to last.
	3g. rb (rotate b):	"	"	"	"	"	"	"	"	"	"	"	"	"	.
	3h.	rr	(ra & rb).

	3i. rra (reverse ra): Shifts left, last element becomes first.
	3j.	rrb (reverse rb): "	"	"	"	"	"	"	"	"	"	".
	3k.	rrr (rra & rrb).

4:	Must deal with errors, write "Error\n" in error output.
	Some errors to look for :
		Some parameters are not number.
		Some parameters are larger/smaller than a int.
		Some paramaters are duplicates.
