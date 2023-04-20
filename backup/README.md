# Instructions

1. Compiler the lexer

```console
flex new.l
```

2. Compile the parser

```console
bison -d new.y
```

3. Write the source ergo program and save it as example.ergo

4. 'Compile' example.ergo

```console
gcc -o output new.tab.c lex.yy.c
```

5. Run the compiler file

```console
./output.exe example.ergo
```