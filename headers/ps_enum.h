#ifndef PS_ENUM_H
# define PS_ENUM_H

typedef enum e_operations
{
	SA = (1 << 0),
	SB = (1 << 1),
	SS = (1 << 2),
	PA = (1 << 3),
	PB = (1 << 4),
	RA = (1 << 5),
	RB = (1 << 6),
	RR = (1 << 7),
	RRA = (1 << 8),
	RRB = (1 << 9),
	RRR = (1 << 10),
	ALL_OP = 0b11111111111
}					t_operations;

/* Not allowed:
	- undo operation
	- this + next replacable by one operation
	- this + next is equal to next + this, AND is covered by another OP_NEXT
*/
typedef enum e_ban
{
	SA_BAN = SS | SB | SA,
	SB_BAN = SS | SB | SA,
	SS_BAN = SS | SB | SA,
	PA_BAN = PB,
	PB_BAN = PA,
	RA_BAN = RB | RRA | RR | RRR,
	RB_BAN = RA | RRB | RR | RRR,
	RR_BAN = RRA | RRB | RRR,
	RRA_BAN = RRB | RA | RRR | RR,
	RRB_BAN = RRA | RB | RRR | RR,
	RRR_BAN = RA | RB | RR
}					t_ban;

typedef enum e_allow
{
	SA_ALLOW = ALL_OP ^ SA_BAN,
	SB_ALLOW = ALL_OP ^ SB_BAN,
	SS_ALLOW = ALL_OP ^ SS_BAN,
	PA_ALLOW = PB,
	PB_ALLOW = PA,
	RA_ALLOW = RB | RRA | RR | RRR,
	RB_ALLOW = RA | RRB | RR | RRR,
	RR_ALLOW = RRA | RRB | RRR,
	RRA_ALLOW = RRB | RA | RRR | RR,
	RRB_ALLOW = RRA | RB | RRR | RR,
	RRR_ALLOW = RA | RB | RR
}					t_allow;

#endif  //PS_ENUM
