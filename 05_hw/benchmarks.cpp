#include <benchmark/benchmark.h>
#include "stack.h"

//Stress functions pop and push of class Stack by using Google Bench lib 
// See more functions in user guide for lib at github https://github.com/google/benchmark/blob/main/docs/user_guide.md

class StackBench : public benchmark::Fixture {
public:
  void SetUp(::benchmark::State& state) {
    stack = new Stack();
  }

  void TearDown(::benchmark::State& state) {
    delete stack;
  }
  Stack* stack;
};


BENCHMARK_DEFINE_F(StackBench, PushTest)(benchmark::State& st) {
   for (auto _ : st) {
    for(int i=0; i < st.range(0); i++){
      stack->push(i);
    }
  }
}

BENCHMARK_DEFINE_F(StackBench, PopTest)(benchmark::State& st) {
    for(int i=0; i < st.range(0); i++){
      stack->push(i);
    }
   for (auto _ : st) {
    for(int i=0; i < st.range(0); i++){
      stack->pop();
    }
  }
}
BENCHMARK_REGISTER_F(StackBench, PushTest)->Arg(100000)->Arg(200000)->Arg(400000)->Arg(80000)->Arg(1600000)->Arg(3200000)->MeasureProcessCPUTime();
BENCHMARK_REGISTER_F(StackBench, PopTest)->Arg(100000)->Arg(200000)->Arg(400000)->Arg(80000)->Arg(1600000)->Arg(3200000)->MeasureProcessCPUTime();

BENCHMARK_MAIN();