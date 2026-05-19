#install dependencies
brew install llvm lld qemu

#download openSBI bin
#curl -LO https://github.com/qemu/qemu/raw/v8.0.4/pc-bios/opensbi-riscv32-generic-fw_dynamic.bin

#add llvm and qemu to path and check llvm-objcopy and llvm packaged clang 
export PATH="$PATH:$(brew --prefix)/opt/llvm/bin"
export PATH="$PATH:$(brew --prefix)/bin/qemu-system-riscv32"
which llvm-objcopy
/opt/homebrew/opt/llvm/bin/llvm-objcopy
which clang
/opt/homebrew/opt/llvm/bin/clang -print-targets 

# create an alias for clang in the llvm directory to support risc32 compilation target
alias clang2='/opt/homebrew/opt/llvm/bin/clang'
which clang2
clang2 -print-targets 