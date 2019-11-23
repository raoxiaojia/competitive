possibleActions = {
    0: '',
    1: '11',
    2: '22',
    3: '33',
    4: '44',
    5: '111',
    6: '222',
    7: '333',
    8: '444'
}


def generateActionList(length):
    actionList = {}
    depth = 1
    prob = 1
    stack = [0]
    actionStack = ['']
    curAction = ''
    while depth > 0:
        #print(actionStack, prob)
        if len(curAction) >= length:
            newAction = ''
            if len(curAction) > length:
                newAction = curAction[:-(len(curAction)-length)]
            else:
                newAction = curAction
            if newAction in actionList:
                actionList[newAction] += prob
            else:
                actionList[newAction] = prob
            depth -= 1
            actionStack.pop()
            curAction = actionStack[-1]
            stack.pop()
            if len(stack) == 1:
                prob *= 8
            else:
                prob *= 6
            continue
        if stack[-1] == 8 or (len(stack) >= 2 and (stack[-2] == 4 or stack[-2] == 8) and stack[-1] == 7):
            depth -= 1
            if depth == 0:
                continue
            actionStack.pop()
            curAction = actionStack[-1]
            stack.pop()
            if len(stack) == 1:
                prob *= 8
            else:
                prob *= 6
            continue
        stack[-1] += 1
        if len(stack) >= 2 and (abs(stack[-1] - stack[-2]) == 4 or stack[-1] == stack[-2]):
            stack[-1] += 1
        curAction = actionStack[-1] + possibleActions[stack[-1]]
        actionStack.append(curAction)
        if len(stack) == 1:
            prob /= 8
        else:
            prob /= 6
        stack.append(0)
        depth = depth + 1
    return actionList

maxDays = 15

actionList = generateActionList(maxDays)
#print(actionList)

def dfs(depth, possibleActionList, curStatus):
    if possibleActionList == {}:
        return [0,0]
    if depth > maxDays:
        return [0,0]
    ret = 0
    bestAction = 0
    bestFollowup = []
    for i in range(4):
        if depth == 1 and i > 0:
            continue
        if depth == 2 and i != 1:
            continue
        if depth == 3 and i != 2:
            continue
        if depth == 4 and i != 3:
            continue
        if depth == 5 and i > 1:
            continue
        curProb = 0
        curAction = []
        curStatus[i] += 1
        actionCategoryList = [{},{},{},{},{}]
        for pAction in possibleActionList:
            actualStatus = [0,0,0,0]
            for j in range(depth):
                actualStatus[ord(pAction[j])-49] += 1
            correctCount = 0
            for j in range(4):
                if (curStatus[j] + actualStatus[j])%2 == 1:
                    correctCount += 1
            actionCategoryList[correctCount][pAction] = possibleActionList[pAction]
            if correctCount == 4:
                curProb += possibleActionList[pAction]
        for j in range(4):
            tmp = dfs(depth+1, actionCategoryList[j], curStatus)
            curProb += tmp[0]
            curAction.append(tmp[1])
        if curProb > ret:
            ret = curProb
            bestAction = i+1
            bestFollowup = curAction
        curStatus[i] -= 1
    return [ret,{'action': bestAction, 'followup': bestFollowup}]

print(dfs(1,actionList,[0,0,0,0]))