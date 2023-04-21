#include <stdio.h>
#include <string>

int ggml_cpu_has_avx(void)
{
#if defined(__AVX__)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_avx2(void)
{
#if defined(__AVX2__)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_avx512(void)
{
#if defined(__AVX512F__)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_fma(void)
{
#if defined(__FMA__)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_neon(void)
{
#if defined(__ARM_NEON)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_arm_fma(void)
{
#if defined(__ARM_FEATURE_FMA)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_f16c(void)
{
#if defined(__F16C__)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_fp16_va(void)
{
#if defined(__ARM_FEATURE_FP16_VECTOR_ARITHMETIC)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_wasm_simd(void)
{
#if defined(__wasm_simd128__)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_blas(void)
{
#if defined(GGML_USE_ACCELERATE) || defined(GGML_USE_OPENBLAS)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_sse3(void)
{
#if defined(__SSE3__)
  return 1;
#else
  return 0;
#endif
}

int ggml_cpu_has_vsx(void)
{
#if defined(__POWER9_VECTOR__)
  return 1;
#else
  return 0;
#endif
}

int main(int argc, char *argv[])
{
  static int avx = ggml_cpu_has_avx();
  static int avx2 = ggml_cpu_has_avx2();
  static int avx512 = ggml_cpu_has_avx512();
  static int fma = ggml_cpu_has_fma();
  static int sse3 = ggml_cpu_has_sse3();
  static std::string s;
  s = "My hardware supports:\n";
  s += "AVX = " + std::to_string(avx) + "\n";
  s += "AVX2 = " + std::to_string(avx2) + "\n";
  s += "AVX512 = " + std::to_string(avx512) + "\n";
  s += "FMA = " + std::to_string(fma) + "\n";
  s += "SSE3 = " + std::to_string(sse3) + "\n";
  printf("%s", s.c_str());
  fflush(stdout);
  return 0;
}
