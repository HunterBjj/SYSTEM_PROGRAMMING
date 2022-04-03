.data 
print_format:
.string "%d\n"
array:
.long 2,12,18,54,26,69,65,66,72,255,243,236,376
array_end:
.text
.global main
.type main, @function

main:
movl $0, %ecx
movl $array,%ebx
movl (%ebx), %eax
jmp ch_bound
loop_start:
and $64, %eax
cmpl $64, %eax
jne less
shrl %cl,(%ebx)
add (%ebx), %ecx
less:
add (%ebx), %ecx
addl $4, %ebx
movl (%ebx), %eax
ch_bound:
cmpl $array_end, %ebx
jne loop_start
pushl %ecx
pushl $print_format
call printf
addl $8, %esp
movl $0, %ecx
movl $0, %ebx
movl $0, %eax
ret

