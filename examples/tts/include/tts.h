#ifndef TTS_H
#define TTS_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LLAMA_API

LLAMA_API void generate_tts(
    const char* prompt,
    const char* model_path,
    const char* vocoder_model_path,
    const char* out_file);

#ifdef __cplusplus
}
#endif

#endif // TTS_H
