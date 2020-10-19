#include <benchmark/benchmark.h>
#include <vector>

static void generate_arg_pairs(benchmark::internal::Benchmark *b) {
  for (int i = 1<<4; i << 10; i <<=2)
    for (int j: {32, 128, 224})
      b = b->ArgPair(i,j);
}

static void bench_fastmod(benchmark::State &state) {
  const int size = state.range(0);
  //const int size = state.range_x();

  // assert(...)
  /* const int ceil = state.range(1); */ 
  //const int ceil = state.range_y(); 
  const int ceil = state.range(1); 
  std::vector<int> input, output;
  input.resize(size, 0);
  output.resize(size, 0);

  while (state.KeepRunning())
    for (int i=0; i<size; ++i)
      output[i] = input[i] >= ceil ? input[i] %ceil : input[i];
}

BENCHMARK(bench_fastmod)->Apply(generate_arg_pairs);

BENCHMARK_MAIN();
