
def getData():
    data = ""
    with open("result.txt") as f:
        data = f.readlines()
    return data

def parseData(lines):
    result = []
    lines = [line.replace("\n", "").split("\t") for line in lines]
    for line in lines:
        if len(line) == 1:
            result.append({'algo': line[0], 'instanceTypes': []})
        else:
            if line[0] not in [instanceType['instanceType'] for instanceType in result[-1]['instanceTypes']]:
                result[-1]['instanceTypes'].append({'instanceType': line[0], 'results': []})
            result[-1]['instanceTypes'][-1]['results'].append({'length': line[1], 'time': line[2]})
    return result

def serializeData(algos):
    result = ""
    for algo in algos:
        for instanceType in algo['instanceTypes']:
            result += algo['algo'] + "\t" + instanceType['instanceType'] + "\n"
            result += "Elementy\tCzas(s)\n"
            for res in instanceType['results']:
                result += res['length'] + "\t" + res['time'] + "\n"
    return result

def saveData(data):
    with open("parsed-result.txt",'w') as f:
        f.write(data)



def main():
    data = getData()
    data = parseData(data)
    data = serializeData(data)
    saveData(data)


if __name__ == '__main__':
    main()
