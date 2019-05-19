#ifndef CHARTYPES_H_INCLUDED
#define CHARTYPES_H_INCLUDED 1

/* TODO: Expand this library to support char sets other than ASCII */


/* TODO: If the execution set is ASCII, use the following definitions: */
	/* ASCII:
		ASCII_TABLE is a bitfield that gives information on each ascii character.
		Each byte in the bitfield corresponds to an ASCII character (sequentially mapped).
		From Lowest Significant Bit to Highest Significant Bit:
			Bit 0: Value is 1 if the character is a lower case letter
			Bit 1: Value is 1 if the character is a upper case letter
			Bit 2: Value is 1 if the character is a digit
			Bit 3: Value is 1 if the character is a control character (non-printable)
			Bit 4: Value is 1 if the character is a white-space character (' ', '\n', '\t', '\v', '\f', '\r')		
			Bit 5: Value is 1 if the character is a punctuation character (!, ", #, $, %, &, ', (, ), *, +, ,, -, ., /, :, ;, <, =, >, ?, @, [, \, ], ^, _, `, {, |, }, ~)
			Bit 6: Value is 1 if the character is a hexidecimal digit character (0-9, a-f, A-F)
			Bit 7: Not used
	*/

	extern const char ASCII_TABLE[];	//Defined in chartypes.c
	#define ascii_range(x) (x <= 127 && x >= 0)
	#define IN_RANGE ascii_range
	#define TABLE ASCII_TABLE
	#define LOWER_BIT 0x01
	#define UPPER_BIT 0x02
	#define ALPHA_BIT 0x03
	#define DIGIT_BIT 0x04
	#define ALNUM_BIT 0x07
	#define CNTRL_BIT 0x08
	#define SPACE_BIT 0x10
	#define PUNCT_BIT 0x20
	#define GRAPH_BIT 0x27
	#define XDIGIT_BIT 0x40
/* TODO: If the execution set is ASCII, use the previous definitions. */


/* TODO: Create other definition sets for when the execution set is not ASCII... */


/* TODO: These should be non-macro functions in chartypes.c so that a program
	using them can change the execution set without recompiling. */
#define is_lower(x) (IN_RANGE(x) && (TABLE[x] & LOWER_BIT))
#define is_upper(x) (IN_RANGE(x) && (TABLE[x] & UPPER_BIT))
#define is_alpha(x) (IN_RANGE(x) && (TABLE[x] & ALPHA_BIT))
#define is_digit(x) (IN_RANGE(x) && (TABLE[x] & DIGIT_BIT))
#define is_alnum(x) (IN_RANGE(x) && (TABLE[x] & ALNUM_BIT))
#define is_cntrl(x) (IN_RANGE(x) && (TABLE[x] & CNTRL_BIT))
#define is_print(x) (!is_cntrl(x))
#define is_space(x) (IN_RANGE(x) && (TABLE[x] & SPACE_BIT))
#define is_punct(x) (IN_RANGE(x) && (TABLE[x] & PUNCT_BIT))
#define is_graph(x) (IN_RANGE(x) && (TABLE[x] & GRAPH_BIT))
#define is_xdigit(x) (IN_RANGE(x) && (TABLE[x] & XDIGIT_BIT))


#endif	//CHARTYPES_H_INCLUDED