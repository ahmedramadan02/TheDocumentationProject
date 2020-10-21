set pagination off
set logging file gdb.txt
set logging on
file output.exe
b main
commands
bt
continue
end
info breakpoints
r
set logging off
quit