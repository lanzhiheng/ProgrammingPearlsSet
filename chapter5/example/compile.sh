gcc -c -fPIC run.c -o binary_search.o
gcc binary_search.o -shared -o binary_search.so

ruby window.rb
