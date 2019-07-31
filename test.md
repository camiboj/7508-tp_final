## rm0

```
$ gcc -std=c11 -Wall -Wextra -g rm0.c -o rm0
rm0.c: In function ‘main’:
rm0.c:9:14: warning: unused parameter ‘argc’ [-Wunused-parameter]
 int main(int argc, char *argv[]) {
              ^~~~
$ echo "this is a test" > test.txt
$ ls
rm0  rm0.c  test.txt
$ ./rm0 test.txt
$ ls
rm0  rm0.c
```
```
$ echo "" > a
$ sisfin ls
a  rm0  rm0.c
$ sisfin ./rm0 a
$  ls
rm0  rm0.c
```

