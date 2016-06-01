t = input()
d = {}
for _ in xrange(t):
	cc, r = map(int, raw_input().split())
	if cc not in d:
		d[cc] = []
	d[cc] += [r]
for i in d.keys():
	l = list(reversed(sorted(d[i])))
	for k in l:
		print i, k