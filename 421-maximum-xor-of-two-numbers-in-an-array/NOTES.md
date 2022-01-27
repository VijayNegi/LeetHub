https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91050/Python-6-lines-bit-by-bit
​
Build the answer bit by bit from left to right (highest bit to lowest bit). Let's say we already know the largest first seven bits we can create. How to find the largest first eight bits we can create? Well it's that maximal seven-bits prefix followed by 0 or 1. Append 0 and then try to create the 1 one (i.e., answer ^ 1) from two eight-bits prefixes from nums. If we can, then change that 0 to 1.
​
Bit more explanation: answer^1 ^ p in prefixes means there's a prefix q in prefixes such that answer^1 ^ p == q. Which means p ^ q == answer ^ 1. So there are two prefixes (p and q) whose xor is answer ^ 1.