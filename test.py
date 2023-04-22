from gpt4allj import Model, load_library

lib = load_library('./lib/avx2/libgptj.dylib', './lib/avx2/libggml.dylib')

model = Model('./ggml-gpt4all-j.bin', lib=lib)

print(model.generate('AI is going to', n_predict=2))
