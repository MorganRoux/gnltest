rm -f prog
rm -f get_next_line*
cp /tmp/alienard/*  .

gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 -I. get_next_line.c get_next_line_utils.c test.c -o prog
./prog < tests/simple

valgrind ./prog

#rm -f prog
