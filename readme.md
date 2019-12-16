# Travelling Salesman Problem

* Branch and bound solver
* Brute force solver

## Execution

```
make
./tsp ./resources/graph4.txt
```

## Execution OpenMP

```
clang -Xpreprocessor -fopenmp -Iinclude -lomp src/main.c -o obj/main.o

или 

gcc -fopenmp file_name.c -o file_name -libomp
gcc -libomp file_name.c -o file_name -libomp

```

* brew install cmake gcc
* cmake -DCMAKE_CXX_COMPILER=g++-6 CMakeLists.txt
* make


https://stackoverflow.com/questions/58275167/mac-running-openmp-clang-error-unsupported-option-fopenmp/58276476#58276476