def plusOne(self, digits: List[int]) -> List[int]:
    s = [str(i) for i in digits]
    res = int("".join(s))
    res=res+1
    final = [int(x) for x in str(res)]
    print(final)