# Bash

## Common Linux Commands

- cd -> change directory
- ls -> view files in the current directory
	- -l for long form listing
	- -a to include all hiddle files as well
	- -h returns humal readble format for various fields
	- can combine ls -al
- pwd -> gives the current directory 
- uniq -> removes consecutive duplicate files (removes all duplicates if sorted)
	- the -c option will print counts of consecutive duplicates
- sort -> Sorts lines of a file/standard input
- tail -> prints last 10 lines of a file/standard input
	- can add -num (-5) to specify the number
- head -> prints the first 10 lines of a file/standard input
	- can add -num (-5) to specify the number of lines
- egrep -> finds patterns in a file and print all the lines that do
	- -n flag gives the lines with line numbers
	- -v flag checks for lines that do not match the pattern
	- -F interprets patterns as fixed strings and not as regular expressions
	- -i ignores case and checks for pattern with case insensitivity
	- -c gives the count of the number of lines that contain the matching pattern
- sort -> sorts the lines of a file
	- -n flag sorts strings of digits in numerical order
- cmp -> compares the files f1 and f2 and outputs the first position where they differ
- wc -> counts the number of words, lines and characters in a file. 
- cat -> prints the file on the terminal

## Regular Expressions

### Practice

Lines that contain both cs246 and cs247, in lower-case.

```bash
"(cs246*cs247)|(cs247*cs246)"
```

Match abcdefg, abcde, abc

```bash
"abc"
```

Match digits - abc123xyz, define "123", var g = 123
```bash
"123"
```

Match - cat. 896. ?=+.
skip - abc1

```bash
.{3}\.
```

Match - can man fan
Skip - dan ran pan

```bash
[cmf]an
```

Match - hog dog
Skip - bog

```bash
[^b]og
```

Match - Ana, Bob, Cpc
Skip - aax, bby, ccz

```bash
[A-C]
```

Match - wazzzzzup, wazzzup
Skip - wazup

```bash
wazz+up
```

Better version:
```bash
waz{3,5}up
```

## Output Redirection

Redirect output using >

```bash
./printer > print.out 2> print.err
```

if we want to redirect the output from standard output to standard error
```bash
- echo "ERROR" 1>&2
```


