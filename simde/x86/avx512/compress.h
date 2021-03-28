#if !defined(SIMDE_X86_AVX512_COMPRESS_H)
#define SIMDE_X86_AVX512_COMPRESS_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_mask_compress_pd (simde__m256d src, simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm256_mask_compress_pd(src, k, a);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a),
      src_ = simde__m256d_to_private(src);
    size_t ri = 0;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; i++) {
      if ((k >> i) & 1) {
        a_.f64[ri++] = a_.f64[i];
      }
    }

    for ( ; ri < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; ri++) {
      a_.f64[ri] = src_.f64[ri];
    }

    return simde__m256d_from_private(a_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_compress_pd
  #define _mm256_mask_compress_pd(src, k, a) _mm256_mask_compress_pd(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm256_mask_compressstoreu_pd (void* base_addr, simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    _mm256_mask_compressstoreu_pd(base_addr, k, a);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a);
    size_t ri = 0;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; i++) {
      if ((k >> i) & 1) {
        a_.f64[ri++] = a_.f64[i];
      }
    }

    simde_memcpy(base_addr, &a_, ri * sizeof(a_.f64[0]));

    return;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_compressstoreu_pd
  #define _mm256_mask_compressstoreu_pd(base_addr, k, a) _mm256_mask_compressstoreu_pd(base_addr, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256d
simde_mm256_maskz_compress_pd (simde__mmask8 k, simde__m256d a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm256_maskz_compress_pd(k, a);
  #else
    simde__m256d_private
      a_ = simde__m256d_to_private(a);
    size_t ri = 0;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.f64) / sizeof(a_.f64[0])) ; i++) {
      if ((k >> i) & 1) {
        a_.f64[ri++] = a_.f64[i];
      }
    }

    for ( ; ri < (sizeof(a_.f64) / sizeof(a_.f64[0])); ri++) {
      a_.f64[ri] = SIMDE_FLOAT64_C(0.0);
    }

    return simde__m256d_from_private(a_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_compress_pd
  #define _mm256_maskz_compress_pd(k, a) _mm256_maskz_compress_pd(k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_mask_compress_ps (simde__m256 src, simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm256_mask_compress_ps(src, k, a);
  #else
    simde__m256_private
      a_ = simde__m256_to_private(a),
      src_ = simde__m256_to_private(src);
    size_t ri = 0;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; i++) {
      if ((k >> i) & 1) {
        a_.f32[ri++] = a_.f32[i];
      }
    }

    for ( ; ri < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; ri++) {
      a_.f32[ri] = src_.f32[ri];
    }

    return simde__m256_from_private(a_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_compress_ps
  #define _mm256_mask_compress_ps(src, k, a) _mm256_mask_compress_ps(src, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_mm256_mask_compressstoreu_ps (void* base_addr, simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    _mm256_mask_compressstoreu_ps(base_addr, k, a);
  #else
    simde__m256_private
      a_ = simde__m256_to_private(a);
    size_t ri = 0;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; i++) {
      if ((k >> i) & 1) {
        a_.f32[ri++] = a_.f32[i];
      }
    }

    simde_memcpy(base_addr, &a_, ri * sizeof(a_.f32[0]));

    return;
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_mask_compressstoreu_pd
  #define _mm256_mask_compressstoreu_ps(base_addr, k, a) _mm256_mask_compressstoreu_ps(base_addr, k, a)
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde__m256
simde_mm256_maskz_compress_ps (simde__mmask8 k, simde__m256 a) {
  #if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
    return _mm256_maskz_compress_ps(k, a);
  #else
    simde__m256_private
      a_ = simde__m256_to_private(a);
    size_t ri = 0;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(a_.f32) / sizeof(a_.f32[0])) ; i++) {
      if ((k >> i) & 1) {
        a_.f32[ri++] = a_.f32[i];
      }
    }

    for ( ; ri < (sizeof(a_.f32) / sizeof(a_.f32[0])); ri++) {
      a_.f32[ri] = SIMDE_FLOAT32_C(0.0);
    }

    return simde__m256_from_private(a_);
  #endif
}
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm256_maskz_compress_ps
  #define _mm256_maskz_compress_ps(k, a) _mm256_maskz_compress_ps(k, a)
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_COMPRESS_H) */