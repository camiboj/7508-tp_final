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
Pruebas:
```
$ gcc -std=c11 -Wall -Wextra -g stat0.c -o stat0
$ stat test.md      //real stat                              
  File: test.md
  Size: 1794      	Blocks: 8          IO Block: 4096   regular file
Device: 10304h/66308d	Inode: 2366520     Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/   camix)   Gid: ( 1000/   camix)
Access: 2019-07-31 16:49:28.984783180 -0300
Modify: 2019-07-31 16:49:28.984783180 -0300
Change: 2019-07-31 16:49:28.988783202 -0300
 Birth: -
$ ./stat0 test.md   //my stat
Size: 1794
File: test.md
Type: regular file
```
```
$ stat test.txt  
  File: test.txt
  Size: 73        	Blocks: 8          IO Block: 4096   regular file
Device: 10304h/66308d	Inode: 2366327     Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/   camix)   Gid: ( 1000/   camix)
Access: 2019-07-31 16:41:40.638215203 -0300
Modify: 2019-07-31 16:41:37.950199880 -0300
Change: 2019-07-31 16:41:37.950199880 -0300
 Birth: -

$ ./stat0 test.txt
Size: 73
File: test.txt
Type: regular file
```
```
$ mkdir another_test
$ stat another_test                             
  File: another_test
  Size: 4096      	Blocks: 8          IO Block: 4096   directory
Device: 10304h/66308d	Inode: 2366529     Links: 2
Access: (0755/drwxr-xr-x)  Uid: ( 1000/   camix)   Gid: ( 1000/   camix)
Access: 2019-07-31 16:44:21.587118154 -0300
Modify: 2019-07-31 16:44:21.555117976 -0300
Change: 2019-07-31 16:44:21.555117976 -0300
 Birth: -

$ ./stat0 another_test 
Size: 4096
File: another_test
Type: directory
```