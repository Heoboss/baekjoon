# 완전수(Perfect Number)를 구하자
# 1. 약수를 판별하는 is_divisor(num1, num2)
# num2가 num1의 약수라면 -> True
# 약수가 아니라면 -> False 리턴!!!
def is_divisor(num1,num2):
    return num1%num2 == 0
    
# 2. 약수를 출력하는 함수!!
# print_divisors(10) -> 10의 약수 : 1 2 5 10
def print_divisors(num):
    print(f"{num}의 약수 :",end=' ')
    for i in range(1,num // 2 + 1):
        if is_divisor(num,i):
            print(f"{i}",end=' ')
    print(num)
    
# 3. 약수의 총합을 구하는 함수
# get_sum_of_divisors(num)
def get_sum_of_divisors(num):
    total = 0
    for i in range(1,num // 2 + 1):
        if is_divisor(num,i):
            total += i
    return int(total+num)

# 4. 완전수 (Perfect Number)
# 자기 자신을 제외한 약수의 총합이
# 자기 자신과 같은 수 -> 완전 수
def is_perfect_number(num):
    return get_sum_of_divisors(num) == num*2
    
N = int(input())
arr = input().split()
for i in range(N):
    if is_perfect_number(int(arr[i])):
        print("Perfect")
    elif get_sum_of_divisors(int(arr[i])) > int(arr[i])*2:
        print("Abundant")
    else:
        print("Deficient")