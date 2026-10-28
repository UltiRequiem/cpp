# Triángulos

A judge-style problem (in Spanish): classify triangles by their angles.

**Input:** a number `n`, then `n` lines with the three angles of a triangle (integers, in degrees).

**Output:** one line per triangle:

| Condition | Output |
|---|---|
| all angles below 90 | `ACUTANGULO` |
| one angle is exactly 90 | `RECTANGULO` |
| otherwise | `OBTUSANGULO` |

```sh
cmake -S . -B build && cmake --build build
printf '3\n60 60 60\n90 45 45\n100 40 40\n' | ./build/triangulos
# ACUTANGULO
# RECTANGULO
# OBTUSANGULO
```

The solution is split in `classify` (the rule) and `run` (the input and output), so the rule can be tested on
its own. See [`test.cpp`](./test.cpp). The first version used a variable-length array (`string results[n]`),
which is not standard C++; it now prints each answer as it reads.
