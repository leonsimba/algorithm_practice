CFLAGS = -I../../lib/
LDFLAGS = -L../../lib/ -lalgor

PROGS = offer003_find_dup_number_in_array       \
		offer004_find_number_in_sorted_matrix   \
		offer005_replace_space					\
		offer006_print_list_in_reversed_order	\
		offer008_next_node_in_binary_tree		\
		offer015_number_of_1_in_binary          \
		offer016_power							\
		offer020_is_numeric_string				\
		offer022_kth_node_from_end				\
		offer024_reverse_list					\
		offer034_find_path_to_specified_value   \
		offer052_get_first_intersecting_node	\
		offer054_get_kth_node_in_bstree         \
		offer058_reverse_words_in_sentence		\
		offer064_accumulate						\
		offer065_add_two_number					\
		offer066_constuct_array					\
		offer067_string_to_int

all: ${PROGS}

offer003_find_dup_number_in_array: offer003_find_dup_number_in_array.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer003_find_dup_number_in_array.o

offer004_find_number_in_sorted_matrix: offer004_find_number_in_sorted_matrix.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer004_find_number_in_sorted_matrix.o

offer005_replace_space: offer005_replace_space.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer005_replace_space.o

offer006_print_list_in_reversed_order: offer006_print_list_in_reversed_order.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer006_print_list_in_reversed_order.o

offer008_next_node_in_binary_tree: offer008_next_node_in_binary_tree.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer008_next_node_in_binary_tree.o

offer015_number_of_1_in_binary: offer015_number_of_1_in_binary.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer015_number_of_1_in_binary.o

offer016_power: offer016_power.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer016_power.o

offer020_is_numeric_string: offer020_is_numeric_string.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer020_is_numeric_string.o

offer022_kth_node_from_end: offer022_kth_node_from_end.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer022_kth_node_from_end.o

offer024_reverse_list: offer024_reverse_list.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer024_reverse_list.o

offer034_find_path_to_specified_value: offer034_find_path_to_specified_value.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer034_find_path_to_specified_value.o

offer052_get_first_intersecting_node: offer052_get_first_intersecting_node.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer052_get_first_intersecting_node.o

offer054_get_kth_node_in_bstree: offer054_get_kth_node_in_bstree.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer054_get_kth_node_in_bstree.o

offer058_reverse_words_in_sentence: offer058_reverse_words_in_sentence.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer058_reverse_words_in_sentence.o

offer064_accumulate: offer064_accumulate.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer064_accumulate.o

offer065_add_two_number: offer065_add_two_numbers.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer065_add_two_numbers.o

offer066_constuct_array: offer066_constuct_array.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer066_constuct_array.o

offer067_string_to_int: offer067_string_to_int.o
		${CC} ${CFLAGS} ${LDFLAGS} -o $@ offer067_string_to_int.o

clean:
		rm -f ${PROGS} *.o
