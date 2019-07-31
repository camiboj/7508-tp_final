## rm0

```
$ gcc -std=c11 -Wall -Wextra -g rm0.c -o rm0
rm0.c: In function ‘main’:
rm0.c:9:14: warning: unused parameter ‘argc’ [-Wunused-parameter]
 int main(int argc, char *argv[]) {
              ^~~~
```
```
$ ls
rm0 test.txt
$ ./rm0 test.txt
$ ls
rm0
```
```
$ ls
a  rm0
$ ./rm0 a
$  ls
rm0 
```

## cat0
```
$ gcc -std=c11 -Wall -Wextra -g cat0.c -o cat0
cat0.c: In function ‘main’:
cat0.c:38:14: warning: unused parameter ‘argc’ [-Wunused-parameter]
 int main(int argc, char *argv[]) {
              ^~~~
```
```
$ echo "this is a test" > test.txt
$ cat test.txt  //real cat
this is a test
$ ./cat0 test.txt   //my cat
this is a test
```
```
$ echo "" > a        
$ ./cat0 a       

$ cat a

```
```
$ echo "this is a test\n\nA REAL TEST" > test.txt
$ ./cat0 test.txt                                
this is a test

A REAL TEST
$ cat test.txt                                
this is a test

A REAL TEST
```

## stat0
Ejemplo dado por la cátedra:
```
$ ./stat0 README.md
Size: 1318
File: README.md
Type: regular file
```