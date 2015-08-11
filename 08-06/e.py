e = 20
delta = 10**e - 1
a = int(input())
# Ha e*45*10**(e-1) digitos em delta. Para chegar em multiplo de a falta:
start = a - (e * 45 * 10**(e-1)) % a
print(start, start+delta)
