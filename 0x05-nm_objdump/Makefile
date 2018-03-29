hnm: main.c
	gcc -Wall -Werror -Wextra -pedantic *.c -o hnm
test_exec_dir=test_executables
hello1: $(test_exec_dir)/hello.c
	gcc -c -Wall -Werror -Wextra -pedantic $(test_exec_dir)/hello.c -o $(test_exec_dir)/hello1.o
hello2: $(test_exec_dir)/hello.c
	gcc -c -ggdb -Wall -Werror -Wextra -pedantic $(test_exec_dir)/hello.c -o $(test_exec_dir)/hello2.o
nm_output_sample:
	gcc -c -ggdb -Wall -Werror -Wextra -pedantic $(test_exec_dir)/nm_output_sample.c -o $(test_exec_dir)/nm_output_sample.o
clean: $(test_exec_dir)/hello1 $(test_exec_dir)/hello2
	rm -f $(test_exec_dir)/hello1 $(test_exec_dir)/hello2
