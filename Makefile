
OUT_FILE=build/gb_emulator.elf
C_COMPILER=clang
C_FLAGS=-Wall -Wextra
SRC= src/main.c

main:
	${C_COMPILER} ${SRC} ${C_FLAGS} -o ${OUT_FILE}
run:
	@./${OUT_FILE}

