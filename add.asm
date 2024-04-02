.386
.model flat, stdcall
option casemap:none

include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib

.data
    prompt db "Press Space", 0
    msg db "Play Game", 0

.code
start:
    ; Print the prompt
    invoke StdOut, addr prompt

    ; Print "Play Game"
    invoke StdOut, addr msg

wait_for_space:
    ; Wait for space key
    invoke StdIn
    cmp al, ' '
    jne wait_for_space

    ; If space is pressed, proceed to the game

    ; Add your game logic here

    ; Exit the program
    invoke ExitProcess, 0
end start