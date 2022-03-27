clothes = []
testcase = int(input())

for i in range(0, testcase):
  N = int(input())
  for j in range(0, N):
    cname, ctype = input().split(' ')
    if not clothes:
      clothes.append([ctype, cname])
    else:
      for k in range(len(clothes)):
        if(ctype == clothes[k][0]):
          clothes[k].append(cname)
          break
        if(k == len(clothes)-1):
          clothes.append([ctype, cname])
  
  result = 1 if N > 0 else 0

  for ctype in clothes:
    cnt = len(ctype)
    result *= cnt
  if(len(clothes) > 0):
    result -= 1

  print(result)
  clothes = []
