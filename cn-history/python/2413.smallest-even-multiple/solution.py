class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        # Check if n is even
        if n % 2 == 0:
            # Even number: smallest even multiple is itself
            return n
        # Odd number: smallest even multiple is n * 2
        return n * 2
