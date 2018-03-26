test_exec_dir=test_executables
hello1:
	gcc -Wall -Werror -Wextra -pedantic $(test_exec_dir)/hello.c -o $(test_exec_dir)/hello1
hello2:
	gcc -ggdb -Wall -Werror -Wextra -pedantic $(test_exec_dir)/hello.c -o $(test_exec_dir)/hello2
clean: $(test_exec_dir)/hello1 $(test_exec_dir)/hello2
	rm -f $(test_exec_dir)/hello1 $(test_exec_dir)/hello2
