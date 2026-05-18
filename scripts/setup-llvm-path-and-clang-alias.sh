export PATH="$PATH:$(brew --prefix)/opt/llvm/bin"
export PATH="$PATH:$(brew --prefix)/bin/qemu-system-riscv32"
which llvm-objcopy
/opt/homebrew/opt/llvm/bin/llvm-objcopy
which clang
/opt/homebrew/opt/llvm/bin/clang -print-targets 
alias clang2='/opt/homebrew/opt/llvm/bin/clang'
which clang2
clang2 -print-targets 