#include <string>
#include <benchmark/benchmark.h>

static void BM_Nothing(benchmark::State& state)
{
    std::string str = "GAO GAO STEGOSAURUS";
    for(auto _ : state)
    {
        std::string copy(str);
    }
}
BENCHMARK(BM_Nothing);

BENCHMARK_MAIN();
