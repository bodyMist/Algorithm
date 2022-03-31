import sys
input = sys.stdin.readline
print = sys.stdout.write

target = input().rstrip()
explosion = input().rstrip()
lenTarget = len(target)
lenEx = len(explosion)
explosionEnd = explosion[-1]
stack = []

for word in target:
  stack.append(word)
  if(word == explosionEnd and ''.join(stack[-lenEx:]) == explosion):
    for _ in range(lenEx):
      stack.pop()

if stack:
  print(f"{''.join(stack)}\n")
else:
  print("FRULA")