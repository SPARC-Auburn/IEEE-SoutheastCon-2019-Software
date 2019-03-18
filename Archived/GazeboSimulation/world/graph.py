import matplotlib.pyplot as plt
x = []
for each in range(14):
	x.append([]);
with open('data.csv', 'r') as f:
	while 1:
		dat = f.readline()
		if dat == '':
			break
		dat = dat.replace("\n","")
		dat = dat.split(",")
		if len(dat) !=14:
			break
		for each in range(14):
			x[each].append(float(dat[each]))
			
ratio = []
ratioDesired = []
for each in range(0,len(x[0])):
	try:
		ratio.append(x[0][each]/x[4][each])
	except:
		ratio.append(0)
	ratioDesired.append(x[1][each]/x[5][each])
plt.figure(1)
plt.subplot(221)
plt.plot(x[0])
plt.plot(x[1])
plt.subplot(223)
plt.plot(x[2])
plt.plot(x[3])
plt.ylabel('right')
plt.subplot(222)
plt.plot(x[4])
plt.plot(x[5])
plt.subplot(224)
plt.plot(x[6])
plt.plot(x[7])
plt.ylabel('left')
plt.figure(2)
plt.plot(ratio)
plt.plot(ratioDesired)

plt.figure(3,figsize=(8, 8), dpi=80)
plt.plot(x[11],x[12]);
plt.plot(x[8],x[9]);
plt.ylim(-2,2)
plt.xlim(-2,2)
plt.show()