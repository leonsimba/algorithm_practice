CFLAGS = -I../../lib/
LDFLAGS = -L../../lib/ -lalgor

PROGS = LC003_longest_substring_without_repearting_characters 	\
		LC015_3Sum 												\
		LC026_remove_duplicates_from_sorted_array				\
		LC033_search_in_rotated_sorted_array					\
		LC080_remove_duplicates_from_sorted_array_II			\
		LC081_search_in_rotated_sorted_array_II

all: ${PROGS}

LC003_longest_substring_without_repearting_characters: LC003_longest_substring_without_repearting_characters.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ LC003_longest_substring_without_repearting_characters.o

LC015_3Sum: LC015_3Sum.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ LC015_3Sum.o

LC026_remove_duplicates_from_sorted_array: LC026_remove_duplicates_from_sorted_array.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ LC026_remove_duplicates_from_sorted_array.o

LC033_search_in_rotated_sorted_array: LC033_search_in_rotated_sorted_array.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ LC033_search_in_rotated_sorted_array.o

LC080_remove_duplicates_from_sorted_array_II: LC080_remove_duplicates_from_sorted_array_II.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ LC080_remove_duplicates_from_sorted_array_II.o

LC081_search_in_rotated_sorted_array_II: LC081_search_in_rotated_sorted_array_II.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ LC081_search_in_rotated_sorted_array_II.o

clean:
		rm -f ${PROGS} *.o
