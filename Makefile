# Makefile

.PHONY: all clean

all:
	@echo "Run \`make folder/filename\` to build, or \`make clean\` to clear all debug and binary files."

%:
	
	@if [ -f "$@.c" ]; then \
		echo "🔧 Building $@.c"; \
		./.vscode/c_cpp_build.sh "$@.c"; \
	elif [ -f "$@.cpp" ]; then \
		echo "🔧 Building $@.cpp"; \
		./.vscode/c_cpp_build.sh "$@.cpp"; \
	else \
		echo "❌ Error: $@.c or $@.cpp not found."; \
		exit 1; \
	fi

clean:
	@echo "🧹 Cleaning *.out and *.dSYM files..."
	@find . -type f -name "*.out" -exec rm -f {} + 2>/dev/null || true
	@find . -type d -name "*.dSYM" -exec rm -rf {} + 2>/dev/null || true
