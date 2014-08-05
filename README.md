# send to tty
a very simple tool to send input to another tty (assume you have the rights), usually you can do
```
echo some string> tty_file 
```
in shell. But if the other tty is waiting for input, like read myVar, it cannot determine the end of line.
this small tool can help to unblock the tty, useful if you have something running in background/batch, waiting for "Y/N/All" etc. and you don't have terminal open. 

## compile
you need gcc, then
```
gcc -o send2tty send2tty.c
```
## Usage
```
send2tty tty_file_name chars_you_want_to_send
```
## example
```
send2tty /dev/pts/23 Y
```

