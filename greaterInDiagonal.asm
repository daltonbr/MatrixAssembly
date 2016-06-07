; Assembly Intel  
  SECTION .text

  global greaterInDiagonal_asm

greaterInDiagonal_asm:
  push ebp
  mov ebp, esp

  xor edx, edx
  xor eax, eax
  xor ecx, ecx
  mov ecx, [ebp+8]  ;L

  mov edx, [ebp+8]
  mov eax, 1
  add eax, ecx   ; ax = L+1
  add eax, eax
  add eax, eax   ; eax = 4*(L+1) , int = 4 bytes

  dec ecx           ; L-1
  mov esi, eax     ; reference to 4*(L+1)

  mov ebx, [ebp+12] ; adress of matrix's first element
  xor edi, edi
loop:
    ;  counter ecx L-1 ~ 0
    mov eax, esi
    mul ecx
    cmp edi, [ebx+eax]    ; compare current max value
    ja continue           ; if not, doesn't change the current max value
    mov edi, [ebx+eax]    ; else...change it
    continue:
    dec ecx
jns loop  ; loop l times

  mov eax, edi
  mov esp, ebp
  pop ebp
  ret
