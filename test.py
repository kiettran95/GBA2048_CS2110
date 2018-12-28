import sys, select, time
while True:
    print "Looping until ENTER pressed"
    time.sleep(1)
    i,o,e = select.select([sys.stdin],[],[],0.0001)
    print(i)
    if i == 'Q': break
print "Goodbye"