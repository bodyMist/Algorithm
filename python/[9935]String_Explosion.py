
target = str(input())
explosion = str(input())
lenTarget = int(len(target))
lenEx = int(len(explosion))

stack = []
output = []
index = 0
for i in range(0,lenTarget):
  if(explosion.find(target[i]) == -1):
    output += stack
    output += target[i]
    stack.clear();
    index = 0
  else:
    stack += target[i]
    index += 1

  if(len(stack) >= lenEx and explosion[lenEx-1] == stack[-1]):
    temp = stack[:index-lenEx]
    stack.clear()
    stack = temp
    index -= lenEx

output+=stack

if(len(output)==0):
  print("FRULA")
else:
  print(''.join(output))