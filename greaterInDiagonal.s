; Assembly Intel
          .text

  global greaterInDiagonal_s

greaterInDiagonal_s:
  push %ebp
  mov %esp,%ebp


  xor %edx, %edx
  xor %eax, %eax
  xor %ecx, %ecx
  mov 8(%ebp), %ecx   ;L


  mov 8(%ebp), %edx
  mov $1,%eax
  add %ecx, %eax     ; ax = L+1
  add %eax, %eax
  add %eax, %eax     ; eax = 4*(L+1) , int = 4 bytes

  dec %ecx           ; L-1
  mov %eax, %esi     ; reference to 4*(L+1)

  mov 12(%ebp),%ebx  ; adress of matrix's first element
  xor %edi, %edi

loop:
    ;  counter ecx L-1 ~ 0
    mov %esi,%eax
    mul %ecx
    cmp %edi, (%ebx + %eax)    ; compare current max value
    ja continue           ; if not, doesn't change the current max value
    mov (%ebx+eax),%edi    ; else...change it
    continue:
    dec %ecx
jns loop  ; loop l times

  mov %edi,%eax
  mov %ebp,%esp
  pop %ebp
  ret
