import random

nums = list(range(0, 100))
random.shuffle(nums)
print(' '.join(map(str, nums)))