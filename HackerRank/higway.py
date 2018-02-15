from decimal import Decimal
a = [[1 for i in xrange(n+1)] for n in xrange(1003)]
	 
for i in xrange(1, 1002):
	for j in xrange(1, i+1):
		a[i+1][j] = a[i][j-1] + a[i][j]
	 
for _ in xrange(int(raw_input())):
	n, g = map(int, raw_input().split())
	n = n - 1
	p = 1e9+9
	s = 0
	ans = [n for _ in xrange(g+1)]
	for i in xrange(1, g+1):
		ans[i] = (pow(n+1, i+1,p)) - 1
		for j in range(2, i+2):
			ans[i] = (ans[i]+p-(a[i+1][j]*ans[i+1-j])%p)%p
		ans[i] = (ans[i]/(i+1))
	print ((ans[g]-1+p) % p)  