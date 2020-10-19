all:
	mkdir build && cd build && conan install -s build_type=Debug --build=benchmark ..

run:
	cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && cmake --build .
	#cd build && gdb ./bin/main
	cd build && ./bin/main

clean:
	rm -rf build
