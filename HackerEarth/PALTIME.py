for i in range(input()):
	a=raw_input();
	b=raw_input();
	count=0;
	for i in range(len(a)):
		c=a[0:i+1]+b+a[i+1:];
		#print c;
		if c==c[::-1]:
			count=count+1;
	c=b+a;
	if c==c[::-1]:
		count=count+1;
	print count;