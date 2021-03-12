import sys
exp = sys.stdin.readline()
formula = []
start = 0

def calculatePriority(index):
    sum = 0
    cnt = index
    for i in range(index, len(formula)):
        if formula[i] != '+' and formula[i] != '-':
            sum += formula[i]
        elif formula[i] == '-':
            break
        cnt += 1
    del formula[index:cnt]
    return sum

def calculateNormal():
    for i in range(len(formula)):
        if i == 0:
            tmp = formula[i]
        elif formula[i] == '+':
            tmp += formula[i+1]
            i += 1
        elif formula[i] == '-':
            tmp -= formula[i+1]
            i += 1
    return tmp
    
for i in range(len(exp)):
    if exp[i] == '+' or exp[i] == '-':
        formula.append(int(exp[start:i]))
        start = i + 1
        formula.append(exp[i])
formula.append(int(exp[start:len(exp)]))

length = len(formula)
for i in range(length):
    if i == length:
        break
    if formula[i] == '-':
        formula.insert(i+1, calculatePriority(i+1))
    length = len(formula)

print(calculateNormal())