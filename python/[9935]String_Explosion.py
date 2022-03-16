from collections import deque

target = str(input())
explosion = str(input())
lenTarget = len(target);
lenEx = len(explosion)

## stack에 넣다가 explosion의 마지막 문자가 입력되면
## explosion의 길이만큼 빼서 검사
## 맞으면 없애고, 아니면 다시 넣기
## stack의 size가 explosion의 길이보다 적다면 그냥 continue


index = 0;

while(True):
  if(target.find(explosion) == -1):
    break
  target = target.replace(explosion, "")


if(target == ""):
  print("FRULA")
else:
  print(target)
