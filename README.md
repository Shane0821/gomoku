# Gomoku
A gomoku player via MiniMax Search and Alpha-Beta Pruning, running on https://botzone.org.cn/.

## How to use
```bash
mkdir build
cd build
cmake ..
make
./gomoku
```

To build shared object, use: 
```bash
cmake .. -DBUILD_SHARED_LIBS=ON 
```

## Techniques
- MinMAX with Alpha-Beta Pruning.
- Zobrist.
- Transposition Table.
- Iterative deepening.

## Sample Matches
https://botzone.org.cn/match/65cf3f5013e80a09c4f159fb
https://botzone.org.cn/match/65d15e8f13e80a09c4f2f5c1
https://botzone.org.cn/match/65d07c2b13e80a09c4f23bf4
https://botzone.org.cn/match/65d36230d43a1d5f79e90cef
