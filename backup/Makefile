target:
		flex lex.l
		bison -d parser.y
		gcc parser.tab.c lex.yy.c
		./a.out example.py
