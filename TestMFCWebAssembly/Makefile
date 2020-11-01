CC=~/emsdk/upstream/emscripten/emcc
SRCFOLDER=/mnt/c/temp2
SOURCES:=$(wildcard $(SRCFOLDER)/*.cpp)
LDFLAGS=-O2 --llvm-opts 2
OUTPUT=/mnt/c/temp2/wa_dialog.js
EMCC_DEBUG=0

all: $(SOURCES) $(OUTPUT)

$(OUTPUT): $(SOURCES) 
	$(CC) $(SOURCES) --bind -s WASM=0 -s EXPORTED_FUNCTIONS="['_OnButtonClick','_main']" -s EXTRA_EXPORTED_RUNTIME_METHODS=['UTF8ToString','lengthBytesUTF8','stringToUTF8'] -s NO_EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1 -s DEMANGLE_SUPPORT=1 -s ASSERTIONS=1 --memory-init-file 0 -D__EMSCRIPTEN__ -std=c++11 $(LDFLAGS) -o $(OUTPUT)

clean:
	rm $(OUTPUT)
